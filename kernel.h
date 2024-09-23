#ifndef KERNEL_H
#define KERNEL_H

#include <cuda_runtime.h>
#include "params.h"
#include <stdint.h>

/*TODO:为什么把这里删除了就可以成功的编译呢？
#if (FPTRU_N == 653)
#include "./poly_mul_n653q/n653.h" //2024-4-22:在这里添加上了对于n653.h的头文件包括
#endif
*/


typedef struct
{
  int16_t coeffs[FPTRU_N];//使用16位有符号数来表示每一个系数
} poly;

//全局的宏定义应该放在全局
#if (FPTRU_N == 653)
#define poly_mul_q1 poly_radix_ntt_n653_q1
#define poly_mul_q2 poly_radix_ntt_n653_q2

#define poly_mul_q1_batch poly_mul_653_batch_q1//DONE
#define poly_mul_q2_batch poly_radix_ntt_n653_q2
#elif (FPTRU_N == 761)
#define poly_mul_q1 poly_radix_ntt_n761_q1
#define poly_mul_q2 poly_radix_ntt_n761_q2

#define poly_mul_q1_batch poly_radix_ntt_n761_q1
#define poly_mul_q2_batch poly_radix_ntt_n761_q2
#elif (FPTRU_N == 1277)
#define poly_mul_q1 poly_radix_ntt_n1277_q1
#define poly_mul_q2 poly_radix_ntt_n1277_q2

#define poly_mul_q1_batch poly_radix_ntt_n1277_q1
#define poly_mul_q2_batch poly_radix_ntt_n1277_q2
#endif

void HandleError(cudaError_t err, const char* file, int line);
#define HANDLE_ERROR( err ) (HandleError( err, __FILE__, __LINE__ ))

#define BEFORE_SPEED {cudaEventCreate( &start );cudaEventCreate( &stop ) ;cudaEventRecord( start, 0 ) ;}

#define AFTER_SPEED(x) {cudaEventRecord( stop, 0 ) ;cudaEventSynchronize( stop );float elapsedTime; cudaEventElapsedTime( &elapsedTime,start, stop ); printf( "%s: %f us\n",x,elapsedTime*1000 );cudaEventDestroy( start );cudaEventDestroy( stop );}

#endif