// 12.28.16: new top-level program for compositing 		vitti@broadinstitute.org
// gcc -O0 -ggdb3 -lm -Wall -o combine_scores combine_scores.c cms_data.c

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "cms_data.h"

/**********/
/***MAIN***/
/**********/

int main(int argc, char **argv) {
	popComp_data_multiple score_data;
	//popComp_data test_data;
	int nComparisons;
	
	//FILE *outf=NULL;
	//char outfilename[256]; 
	//int isnp;

	if (argc <= 2) {
		fprintf(stderr, "Usage: ./combine_scores <cms_run_paramfile> <input_pair_file1> ...\n");
		exit(0);
	}
	nComparisons = argc - 2;

	//<cms_run_paramfile> has selpop and altpops and dem model and other options
	//	* some number of (pop-pairs), with a file for each (which in turn lists score files for each poppair to popComp)
	//	* likes: options (likesFreqs?) and top-level files
	//	* tosavefile? any other options? (maf filter? decompose? bf?)
	// 	* REGION? maybe this is separate/secondary? 

	//////////////////
	// LOAD SCORES ///
	//////////////////
	fprintf(stderr, "Preparing to load component scores...\n");

	//get_popComp_data(&test_data, "/n/regal/sabeti_lab/jvitti/clear/scores/nulldefault/neut/ihs/rep1_1.ihs.out.norm", "/n/regal/sabeti_lab/jvitti/clear/scores/nulldefault/neut/delihh/rep1_1.txt.norm", "/n/regal/sabeti_lab/jvitti/clear/scores/nulldefault/neut/nsl/rep1_1.nsl.out.norm", "/n/regal/sabeti_lab/jvitti/clear/scores/nulldefault/neut/xpehh/rep1_1_2.xpehh.out.norm", "/n/regal/sabeti_lab/jvitti/clear/scores/nulldefault/neut/fst_deldaf/rep1_1_2");
	//fprintf(stderr, "%d\n", argc);
	get_popComp_data_multiple(&score_data, nComparisons, argc, argv); //this 

	/////////////////////////////
	// LOAD SCORE LIKELIHOODS ///
	/////////////////////////////
	//fprintf(stderr, "Preparing to load score likelihoods...\n");
	//get_likes_data_multiple(&likes_data, argc, argv); 

	////////////////////////
	// ITERATE OVER SNPS ///
	////////////////////////
	//outf = fopen(outfilename, "w");
	//assert(outf != NULL);
	//fprintf(stderr, "Preparing to write to: %s\n", outfilename);
	//for (isnp = 0; isnp < score_data.nsnps; isnp++){
		//////////////////////////////////
		//HANDLE POPULATION COMPARISONS //
		//////////////////////////////////


		//compLikeRatio = delihh_bf * nsl_bf  * fst_bf * deldaf_bf * xpehh_bf; //* ihs_bf
		//fprintf(outf, "%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%e\n", score_data.physpos[iComp][isnp], score_data.genpos[iComp][isnp], thisihs, thisihh, thisnsl, thisxpehh, thisfst, thisdelDaf, compLikeRatio);
	//} // end isnp
	//fclose(outf);
	fprintf(stderr, "well, that's a wrap.\n");
	free_popComp_data_multiple(&score_data);
	return 0;
} // end main