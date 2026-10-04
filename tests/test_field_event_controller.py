"""Run the guarded controller unchanged with real 32-bit records and call contracts."""
from pathlib import Path
import sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNER=ROOT/'src/promoted/k_fldEvent.c'
def source(mutant=None):
    body=Q.function_bodies(OWNER)['func_00172e00'][1]
    if mutant:
        old,new=mutant
        if old not in body:raise AssertionError('stale mutant '+old)
        body=body.replace(old,new,1)
    return (RUNTIME_C+(ROOT/'tests/fixtures/field_event_controller_fixture.c').read_text()+body+
            (ROOT/'tests/fixtures/field_event_controller_main.c').read_text()+ENTRY_C)
class FieldEventController(unittest.TestCase):
    def run_fixture(self,code,opt):
        runtime=native32_runtime()
        with tempfile.TemporaryDirectory(prefix='field-event-') as d:
            p=Path(d);c=p/'test.c';c.write_text(code)
            return runtime.run(runtime.compile(c,p/'test',opt,(ROOT/'include',)))
    def test_controller(self):
        for opt in ['-O0','-O2']:
            result=self.run_fixture(source(),opt)
            self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            print(result.stdout.strip())
    def test_negative_controls(self):
        mutants=[('work->frameCounter = 0;','work->frameCounter = 1;'),
                 ('cb < (lim + 5)','cb < (lim + 4)'),
                 ('candidate->active != 0','candidate->active == 0'),
                 ('nearbyCount >= 2','nearbyCount >= 1'),
                 ('cameraTarget.y += 100.0f','cameraTarget.y += 99.0f'),
                 ('work->battle.flags | 8','work->battle.flags | 4'),
                 ('work->snapshot = snapshot;','work->snapshot.words[0] = snapshot.words[0];'),
                 ('work->target->unit->count > 0','work->target->unit->count == 0'),
                 ('work->eventPending = 1','work->eventPending = 0')]
        for mutation in mutants:
            with self.subTest(mutation=mutation[0]):
                r=self.run_fixture(source(mutation),'-O2')
                self.assertNotEqual(r.returncode,0,'mutant escaped '+str(mutation))
if __name__=='__main__':unittest.main()
