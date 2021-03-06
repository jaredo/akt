#ifndef AKT_H
#define AKT_H

#define __STDC_LIMIT_MACROS

#include "version.hh"
#include <stdint.h>
#include <vector>
#include <string>
#include <getopt.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdlib.h> 
#include <stdio.h> 
#include <iterator>
#include <map>
#include <list>
#include <algorithm>
#include <set>
#include <stdexcept>
#include <assert.h>

extern "C" {
#include "htslib/synced_bcf_reader.h"
#include "htslib/hts.h"    
}

#include "samples.hh"
#include "utils.hh"

#ifdef _OPENMP
   #include <omp.h>
#else
static int inline omp_get_thread_num() {
  std::cerr<<"WARNING: threading is disabled"<<endl;
  return(0);
}
static int inline omp_get_num_threads() {
  std::cerr<<"WARNING: threading is disabled"<<endl;
  return(0);
}
static void inline omp_set_num_threads(int nthreads) {} 
#endif


template <typename T> string to_string( T x ){ 
	return static_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str(); 
}
        
using namespace std;

int pca_main(int argc,char **argv);

int kin_main(int argc,char **argv);

int relatives_main(int argc,char **argv);

int unrelated_main(int argc,char **argv);

int r2_main(int argc, char **argv);
int pedphase_main(int argc, char **argv);

int grm(bcf_srs_t *sr);
int prune_main(int argc,char **argv);


#endif  //AKT_H
