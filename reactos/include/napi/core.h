#ifndef __INCLUDE_NAPI_CORE_H
#define __INCLUDE_NAPI_CORE_H

#define MM_CORE_DUMP_HEADER_MAGIC         (0xdeafbead)
#define MM_CORE_DUMP_HEADER_VERSION       (0x1)

#include <ddk/ntddscsi.h>
typedef struct _MM_CORE_DUMP_HEADER
{
  ULONG Magic;
  ULONG Version;
  ULONG Type;
  KTRAP_FRAME TrapFrame;
  ULONG BugCheckCode;
  ULONG BugCheckParameters[4];
  PVOID FaultingStackBase;
  ULONG FaultingStackSize;
  ULONG PhysicalMemorySize;
} MM_CORE_DUMP_HEADER, *PMM_CORE_DUMP_HEADER;

typedef struct MM_CORE_DUMP_FUNCTIONS
{
  NTSTATUS (STDCALL *DumpPrepare)(PDEVICE_OBJECT DeviceObject, PDUMP_POINTERS DumpPointers);
  NTSTATUS (STDCALL *DumpInit)(VOID);
  NTSTATUS (STDCALL *DumpWrite)(LARGE_INTEGER Address, PMDL Mdl);
  NTSTATUS (STDCALL *DumpFinish)(VOID);
} MM_CORE_DUMP_FUNCTIONS, *PMM_CORE_DUMP_FUNCTIONS;

#endif /* __INCLUDE_NAPI_CORE_H */
