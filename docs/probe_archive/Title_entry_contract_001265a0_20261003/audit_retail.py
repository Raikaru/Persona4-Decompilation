from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
R=Path(__file__).resolve().parent
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS);e=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
words={0x1265d4:0x00a0202d,0x1265d8:0x0c114958,0x1265dc:0,
 0x4623b8:0x8e060008,0x4623e0:0x2604001c,0x4623e4:0x8e050010,0x4623e8:0x00c0f809,0x4623ec:0,0x4623f0:0x96030018,
 0x12b60c:0x0c118264,0x12b614:0x0040282d,0x12b618:0x3c030012,0x12b61c:0x246365a0,0x12b620:0xac430008,0x12b624:0xac530010,0x12b630:0x0c1182b0,
 0x452560:0x8c820038,0x452564:0x03e00008,0x452568:0,0x12aa8c:0x0080982d}
for a,w in words.items():assert e.bytes_at(a,4)==struct.pack('<I',w),(hex(a),hex(w),e.bytes_at(a,4).hex())
r={'retail_sha1':windows['sha1'],'checked_words':{hex(a):hex(w) for a,w in words.items()},'callback_node_field':8,'callback_data_field':16,'callback_first_argument':'node+0x1c','callback_second_argument':'word at node+0x10','target_accessor_argument':'incoming a1 forwarded to a0','accessor_load':'word at task+0x38','callback_result_consumed':False,'scope':'Authenticated retail registration, two-input dispatch, target forwarding and accessor; dispatcher C is not executed'}
(R/'authenticated-retail-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print('Authenticated callback registration, two-input dispatch, target a1 forwarding and task-work accessor')
