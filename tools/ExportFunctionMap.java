// Run in Ghidra with the analyzed SLUS_217.82 program open.
// Args: <functions-json> <symbol-addrs> <retail-elf-sha1>

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ExportFunctionMap extends GhidraScript {
    private static String jsonEscape(String value) {
        return value.replace("\\", "\\\\").replace("\"", "\\\"");
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) {
            throw new IllegalArgumentException(
                "usage: ExportFunctionMap.java <functions-json> <symbol-addrs> <retail-elf-sha1>");
        }

        List<Function> functions = new ArrayList<>();
        for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
            if (!function.isExternal()) {
                functions.add(function);
            }
        }
        functions.sort(Comparator.comparing(Function::getEntryPoint));

        File jsonFile = new File(args[0]);
        File symbolFile = new File(args[1]);
        jsonFile.getParentFile().mkdirs();
        symbolFile.getParentFile().mkdirs();

        try (BufferedWriter json = new BufferedWriter(new FileWriter(jsonFile));
             BufferedWriter symbols = new BufferedWriter(new FileWriter(symbolFile))) {
            json.write("{\n");
            json.write("  \"program\": \"" + jsonEscape(currentProgram.getName()) + "\",\n");
            json.write("  \"sha1\": \"" + jsonEscape(args[2]) + "\",\n");
            json.write("  \"generated_from\": \"Ghidra analyzed function bodies\",\n");
            json.write("  \"function_count\": " + functions.size() + ",\n");
            json.write("  \"windows\": {\n");

            symbols.write("// Auto-generated Persona 4 USA function symbols from Ghidra.\n");
            symbols.write("// Format: name = 0xADDR; // type:func\n");

            for (int index = 0; index < functions.size(); index++) {
                Function function = functions.get(index);
                Address entry = function.getEntryPoint();
                Address end = function.getBody().getMaxAddress();
                long size = end.subtract(entry) + 1;
                if (size <= 0 || size > 0xffffffffL) {
                    throw new IllegalStateException("invalid function body for " + function.getName());
                }

                json.write(String.format("    \"%08x\": %d%s\n",
                    entry.getOffset(), size, index + 1 == functions.size() ? "" : ","));
                symbols.write(String.format("%s = 0x%08X; // type:func\n",
                    function.getName(), entry.getOffset()));
            }

            json.write("  }\n");
            json.write("}\n");
        }

        println("Exported " + functions.size() + " functions to " + jsonFile + " and " + symbolFile);
    }
}
