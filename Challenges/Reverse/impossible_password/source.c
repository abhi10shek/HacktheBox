#include<time.h>
void * FUN_0040078d(int param_1)//20
{
  int iVar1;
  time_t tVar2;
  void *pvVar3;
  int local_c;
  
  tVar2 = time((time_t *)0x0);
  DAT_00601074 = DAT_00601074 + 1;
  srand(DAT_00601074 + (int)tVar2 * 20);
  pvVar3 = malloc((long)(21));
  if (pvVar3 != (void *)0x0) {
    local_c = 0;
    while (local_c < 20) {
      iVar1 = rand();
      pvVar3[local_c] = (char)(iVar1 % 94) + '!';
      local_c = local_c + 1;
    }
    // *(undefined *)((long)pvVar3 + (long)param_1) = 0;
    return pvVar3;
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}


void FUN_00400978(byte *param_1)

{
  int local_14;
  byte *local_10;
  
  local_14 = 0;
  local_10 = param_1;
  while ((*local_10 != 9 && (local_14 < 20))) {
    putchar((int)(char)(*local_10 ^ 9));
    local_10 = local_10 + 1;
    local_14 = local_14 + 1;
  }
  putchar(10);
  return;
}

local_48 = 0x41;
local_47 = 0x5d;
local_46 = 0x4b;
local_45 = 0x72;
local_44 = 0x3d;
local_43 = 0x39;
local_42 = 0x6b;
local_41 = 0x30;
local_40 = 0x3d;
local_3f = 0x30;
local_3e = 0x6f;
local_3d = 0x30;
local_3c = 0x3b;
local_3b = 0x6b;
local_3a = 0x31;
local_39 = 0x3f;
local_38 = 0x6b;
local_37 = 0x38;
local_36 = 0x31;
local_35 = 0x74;