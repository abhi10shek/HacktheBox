void maybe_main(int param_1,long param_2)

{
  char cVar1;
  int iVar2;
  time_t tVar3;
  char local_9;
  
  tVar3 = time((time_t *)0x0);
  srand((uint)tVar3);
  iVar2 = rand();
  cVar1 = (char)iVar2 + (char)(-iVar2) + '\x01';
  local_9 = cVar1;
  if (1 < param_1) {
    iVar2 = atoi(*(char **)(param_2 + 8));
    local_9 = (char)iVar2;
    if ((local_9 < '\0') || (local_9 == '\x7f')) {
      local_9 = cVar1;
    }
  }
  iVar2 = lookinto1();//1
  if (iVar2 != 0) {
    lookinto2(&DAT_006020e0,(ulong)(uint)(int)local_9);
  }
  return;
}


int lookinto1(void)
{
  int iVar1;
  undefined8 uVar2;
  char local_78;
  char local_77;
  char local_76;
  char local_75;
  FILE *local_10;
  
  local_10 = fopen("/tmp/secret","rb");
  if (local_10 == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    exit(-2);
  }
  memset(&local_78,0,100);
  fread(&local_78,1,100,local_10);
  iVar1 = strcmp(&local_78,'VerySuperSeKretKey');
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if ((((local_78 == -34) && (local_77 == -83)) && (local_76 == -66)) && (local_75 == -17))
  {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


void lookinto2(byte *param_1,byte param_2)

{
  long lVar1;
  int local_14;
  byte *local_10;
  
  local_14 = 0;
  local_10 = param_1;
  while (*local_10 != param_2) {
    if (17 < local_14) break;
    printf("%x",(ulong)(uint)(int)(char)(*local_10 ^ param_2));
    local_10 = local_10 + 1;
    local_14 = local_14 + 1;
  }
  lVar1 = ptrace(PTRACE_TRACEME,0,0,0);
  if (lVar1 == -1) {
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  putchar(10);
  puts("Are you sure it\'s the right one? ..");
  return;
}


void lookinto3(byte param_1)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  int local_14;
  byte *local_10;
  
  local_10 = &DAT_006020c0;
  local_14 = 0;
  lVar3 = ptrace(PTRACE_TRACEME,0,0,0);
  if (lVar3 != -1) {
    while ((*local_10 != param_1 &&
           (iVar1 = local_14 + 1, bVar2 = local_14 < 24, local_14 = iVar1, bVar2))) {
      printf("%x",(ulong)(uint)(int)(char)(*local_10 ^ param_1));
      local_10 = local_10 + 1;
    }
    putchar(10);
    printf("--hit any key");
    __isoc99_scanf(&DAT_00400cba,&local_14);
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}