#include "CRF.h"

SEXP Infer_RBP(SEXP _crf, SEXP _maxIter, SEXP _cutoff, SEXP _verbose, SEXP _maximize)
{
	int maxIter = INTEGER_POINTER(AS_INTEGER(_maxIter))[0];
	double cutoff = NUMERIC_POINTER(AS_NUMERIC(_cutoff))[0];
	int verbose = INTEGER_POINTER(AS_INTEGER(_verbose))[0];
	bool maximize = LOGICAL_POINTER(AS_LOGICAL(_maximize))[0];

	CRF crf(_crf);
	crf.Init_Belief();
	crf.Infer_RBP(maxIter, cutoff, verbose, maximize);

	return(crf._belief);
}

void CRF::Infer_RBP(int maxIter, double cutoff, int verbose, bool maximize)
{
	ResidualBP(maxIter, cutoff, verbose, maximize);
	Messages2EdgeBel();
	BetheFreeEnergy();
}
