
#include <stdint.h>
#include "bpacking64_default.h"
#include <assert.h>
namespace arrow {
namespace internal{
int unpack64_default(const uint8_t* in, uint64_t* out, int batch_size, int num_bits) {
  batch_size = batch_size / 32 * 32;
  int num_loops = batch_size / 32;

  switch (num_bits) {
    case 0:
      for (int i = 0; i < num_loops; ++i) in = unpack0_64(in, out + i * 32);
      break;
    case 1:
      for (int i = 0; i < num_loops; ++i) in = unpack1_64(in, out + i * 32);
      break;
    case 2:
      for (int i = 0; i < num_loops; ++i) in = unpack2_64(in, out + i * 32);
      break;
    case 3:
      for (int i = 0; i < num_loops; ++i) in = unpack3_64(in, out + i * 32);
      break;
    case 4:
      for (int i = 0; i < num_loops; ++i) in = unpack4_64(in, out + i * 32);
      break;
    case 5:
      for (int i = 0; i < num_loops; ++i) in = unpack5_64(in, out + i * 32);
      break;
    case 6:
      for (int i = 0; i < num_loops; ++i) in = unpack6_64(in, out + i * 32);
      break;
    case 7:
      for (int i = 0; i < num_loops; ++i) in = unpack7_64(in, out + i * 32);
      break;
    case 8:
      for (int i = 0; i < num_loops; ++i) in = unpack8_64(in, out + i * 32);
      break;
    case 9:
      for (int i = 0; i < num_loops; ++i) in = unpack9_64(in, out + i * 32);
      break;
    case 10:
      for (int i = 0; i < num_loops; ++i) in = unpack10_64(in, out + i * 32);
      break;
    case 11:
      for (int i = 0; i < num_loops; ++i) in = unpack11_64(in, out + i * 32);
      break;
    case 12:
      for (int i = 0; i < num_loops; ++i) in = unpack12_64(in, out + i * 32);
      break;
    case 13:
      for (int i = 0; i < num_loops; ++i) in = unpack13_64(in, out + i * 32);
      break;
    case 14:
      for (int i = 0; i < num_loops; ++i) in = unpack14_64(in, out + i * 32);
      break;
    case 15:
      for (int i = 0; i < num_loops; ++i) in = unpack15_64(in, out + i * 32);
      break;
    case 16:
      for (int i = 0; i < num_loops; ++i) in = unpack16_64(in, out + i * 32);
      break;
    case 17:
      for (int i = 0; i < num_loops; ++i) in = unpack17_64(in, out + i * 32);
      break;
    case 18:
      for (int i = 0; i < num_loops; ++i) in = unpack18_64(in, out + i * 32);
      break;
    case 19:
      for (int i = 0; i < num_loops; ++i) in = unpack19_64(in, out + i * 32);
      break;
    case 20:
      for (int i = 0; i < num_loops; ++i) in = unpack20_64(in, out + i * 32);
      break;
    case 21:
      for (int i = 0; i < num_loops; ++i) in = unpack21_64(in, out + i * 32);
      break;
    case 22:
      for (int i = 0; i < num_loops; ++i) in = unpack22_64(in, out + i * 32);
      break;
    case 23:
      for (int i = 0; i < num_loops; ++i) in = unpack23_64(in, out + i * 32);
      break;
    case 24:
      for (int i = 0; i < num_loops; ++i) in = unpack24_64(in, out + i * 32);
      break;
    case 25:
      for (int i = 0; i < num_loops; ++i) in = unpack25_64(in, out + i * 32);
      break;
    case 26:
      for (int i = 0; i < num_loops; ++i) in = unpack26_64(in, out + i * 32);
      break;
    case 27:
      for (int i = 0; i < num_loops; ++i) in = unpack27_64(in, out + i * 32);
      break;
    case 28:
      for (int i = 0; i < num_loops; ++i) in = unpack28_64(in, out + i * 32);
      break;
    case 29:
      for (int i = 0; i < num_loops; ++i) in = unpack29_64(in, out + i * 32);
      break;
    case 30:
      for (int i = 0; i < num_loops; ++i) in = unpack30_64(in, out + i * 32);
      break;
    case 31:
      for (int i = 0; i < num_loops; ++i) in = unpack31_64(in, out + i * 32);
      break;
    case 32:
      for (int i = 0; i < num_loops; ++i) in = unpack32_64(in, out + i * 32);
      break;
    case 33:
      for (int i = 0; i < num_loops; ++i) in = unpack33_64(in, out + i * 32);
      break;
    case 34:
      for (int i = 0; i < num_loops; ++i) in = unpack34_64(in, out + i * 32);
      break;
    case 35:
      for (int i = 0; i < num_loops; ++i) in = unpack35_64(in, out + i * 32);
      break;
    case 36:
      for (int i = 0; i < num_loops; ++i) in = unpack36_64(in, out + i * 32);
      break;
    case 37:
      for (int i = 0; i < num_loops; ++i) in = unpack37_64(in, out + i * 32);
      break;
    case 38:
      for (int i = 0; i < num_loops; ++i) in = unpack38_64(in, out + i * 32);
      break;
    case 39:
      for (int i = 0; i < num_loops; ++i) in = unpack39_64(in, out + i * 32);
      break;
    case 40:
      for (int i = 0; i < num_loops; ++i) in = unpack40_64(in, out + i * 32);
      break;
    case 41:
      for (int i = 0; i < num_loops; ++i) in = unpack41_64(in, out + i * 32);
      break;
    case 42:
      for (int i = 0; i < num_loops; ++i) in = unpack42_64(in, out + i * 32);
      break;
    case 43:
      for (int i = 0; i < num_loops; ++i) in = unpack43_64(in, out + i * 32);
      break;
    case 44:
      for (int i = 0; i < num_loops; ++i) in = unpack44_64(in, out + i * 32);
      break;
    case 45:
      for (int i = 0; i < num_loops; ++i) in = unpack45_64(in, out + i * 32);
      break;
    case 46:
      for (int i = 0; i < num_loops; ++i) in = unpack46_64(in, out + i * 32);
      break;
    case 47:
      for (int i = 0; i < num_loops; ++i) in = unpack47_64(in, out + i * 32);
      break;
    case 48:
      for (int i = 0; i < num_loops; ++i) in = unpack48_64(in, out + i * 32);
      break;
    case 49:
      for (int i = 0; i < num_loops; ++i) in = unpack49_64(in, out + i * 32);
      break;
    case 50:
      for (int i = 0; i < num_loops; ++i) in = unpack50_64(in, out + i * 32);
      break;
    case 51:
      for (int i = 0; i < num_loops; ++i) in = unpack51_64(in, out + i * 32);
      break;
    case 52:
      for (int i = 0; i < num_loops; ++i) in = unpack52_64(in, out + i * 32);
      break;
    case 53:
      for (int i = 0; i < num_loops; ++i) in = unpack53_64(in, out + i * 32);
      break;
    case 54:
      for (int i = 0; i < num_loops; ++i) in = unpack54_64(in, out + i * 32);
      break;
    case 55:
      for (int i = 0; i < num_loops; ++i) in = unpack55_64(in, out + i * 32);
      break;
    case 56:
      for (int i = 0; i < num_loops; ++i) in = unpack56_64(in, out + i * 32);
      break;
    case 57:
      for (int i = 0; i < num_loops; ++i) in = unpack57_64(in, out + i * 32);
      break;
    case 58:
      for (int i = 0; i < num_loops; ++i) in = unpack58_64(in, out + i * 32);
      break;
    case 59:
      for (int i = 0; i < num_loops; ++i) in = unpack59_64(in, out + i * 32);
      break;
    case 60:
      for (int i = 0; i < num_loops; ++i) in = unpack60_64(in, out + i * 32);
      break;
    case 61:
      for (int i = 0; i < num_loops; ++i) in = unpack61_64(in, out + i * 32);
      break;
    case 62:
      for (int i = 0; i < num_loops; ++i) in = unpack62_64(in, out + i * 32);
      break;
    case 63:
      for (int i = 0; i < num_loops; ++i) in = unpack63_64(in, out + i * 32);
      break;
    case 64:
      for (int i = 0; i < num_loops; ++i) in = unpack64_64(in, out + i * 32);
      break;
    default:
      assert(false);
  }

  return batch_size;
}


int unpack64(const uint8_t* in, uint64_t* out, int batch_size, int num_bits) {
  // TODO: unpack64_neon, unpack64_avx2 and unpack64_avx512
  return unpack64_default(in, out, batch_size, num_bits);
}
}
}