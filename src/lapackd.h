// -*- c++ -*-
// $Id: lapackd.h,v 1.12 2000/08/11 23:11:34 bates Exp $

// C++ prototypes for double precision Lapack routines.

// All arguments to Fortran routines must be passed as pointers or
// references.  Arguments that will be used as scalars are passed as
// references.  Arguments that will be used as arrays are passed as
// pointers.  The const keyword modifies those arguments that are
// guaranteed to be unchanged on exit.

// Copyright (C) 2000-2000 the R Development Core Team

extern "C" {
#include <R_ext/RS.h>		// to define F77_NAME

    // DBDSQR - compute the singular value decomposition (SVD) of a real
    // N-by-N (upper or lower) bidiagonal matrix B 
    void F77_NAME(dbdsqr)(const char& uplo, const int& n,
			  const int& ncvt, const int& nru,
			  const int& ncc, double* d, double* e,
			  double* vt, const int& ldvt,
			  double* u, const int& ldu,
			  double* c, const int& ldc,
			  double* work, int& info);

    // DDISNA - compute the reciprocal condition numbers for the
    // eigenvectors of a real symmetric or complex Hermitian matrix or
    // for the left or right singular vectors of a general m-by-n
    // matrix
    void F77_NAME(ddisna)(const char& job, const int& m, const int& n,
			  double* d, double* sep, int& info);

    // DGBBRD - reduce a real general m-by-n band matrix A to upper
    // bidiagonal form B by an orthogonal transformation 
    void F77_NAME(dgbbrd)(const char& vect, const int& m, const int& n,
			  const int& ncc, const int& kl, const int& ku,
			  double* ab, const int& ldab,
			  double* d, double* e, double* q,
			  const int& ldq, double* pt, const int& ldpt,
			  double* c, const int& ldc,
			  double* work, int& info);

    // DGBCON - estimate the reciprocal of the condition number of a
    // real general band matrix A, in either the 1-norm or the
    // infinity-norm
    void F77_NAME(dgbcon)(const char& norm, const int& n,
			  const int& kl, const int& ku,
			  double* ab, const int& ldab,
			  int* ipiv, const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DGBEQU - compute row and column scalings intended to
    // equilibrate an M-by-N band matrix A and reduce its condition
    // number 
    void F77_NAME(dgbequ)(const int& m, const int& n,
			  const int& kl, const int& ku,
			  double* ab, const int& ldab,
			  double* r, double* c,
			  double* rowcnd, double* colcnd,
			  double* amax, int& info);

    // DGBRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is banded, and provides
    // error bounds and backward error estimates for the solution
    void F77_NAME(dgbrfs)(const char& trans, const int& n,
			  const int& kl,const int& ku, const int& nrhs,
			  double* ab, const int& ldab,
			  double* afb, const int& ldafb,
			  int* ipiv, double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DGBSV - compute the solution to a real system of linear
    // equations A * X = B, where A is a band matrix of order N with
    // KL subdiagonals and KU superdiagonals, and X and B are
    // N-by-NRHS matrices
    void F77_NAME(dgbsv)(const int& n, const int& kl,const int& ku,
			 const int& nrhs, double* ab, const int& ldab,
			 int* ipiv, double* b, const int& ldb, int& info);

    // DGBSVX - use the LU factorization to compute the solution to a
    // real system of linear equations A * X = double* b, A**T * X = B, or
    // A**H * X = B,
    void F77_NAME(dgbsvx)(const int& fact, const char& trans,
			  const int& n, const int& kl,const int& ku,
			  const int& nrhs, double* ab, const int& ldab,
			  double* afb, const int& ldafb, int* ipiv,
			  const char& equed, double* r, double* c, 
			  double* b, const int& ldb,
			  double* x, const int& ldx,
			  double& rcond, double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DGBTF2 - compute an LU factorization of a real m-by-n band
    // matrix A using partial pivoting with row interchanges
    void F77_NAME(dgbtf2)(const int& m, const int& n,
			  const int& kl,const int& ku,
			  double* ab, const int& ldab,
			  int* ipiv, int& info);

    // DGBTRF - compute an LU factorization of a real m-by-n band
    // matrix A using partial pivoting with row interchanges
    void F77_NAME(dgbtrf)(const int& m, const int& n,
			  const int& kl,const int& ku,
			  double* ab, const int& ldab,
			  int* ipiv, int& info);

    // DGBTRS - solve a system of linear equations  A * X = B or A' *
    // X = B with a general band matrix A using the LU factorization
    // computed by DGBTRF
    void F77_NAME(dgbtrs)(const char& trans, const int& n,
			  const int& kl,const int& ku,
			  const int& nrhs, double* ab, const int& ldab,
			  int* ipiv, double* b, const int& ldb,
			  int& info);

    // DGEBAK - form the right or left eigenvectors of a real general
    // matrix by backward transformation on the computed eigenvectors
    // of the balanced matrix output by DGEBAL 
    void F77_NAME(dgebak)(const char& job, const char& side, const int& n,
			  const int& ilo, const int& ihi,
			  double* scale, const int& m,
			  double* v, const int& ldv, int& info);

    // DGEBAL - balance a general real matrix A
    void F77_NAME(dgebal)(const char& job, const int& n,
			  double* a, const int& lda,
			  int* ilo, int* ihi, double* scale,
			  int& info);

    // DGEBD2 - reduce a real general m by n matrix A to upper or
    // lower bidiagonal form B by an orthogonal transformation
    void F77_NAME(dgebd2)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* d, double* e, double* tauq,
			  double* taup, double* work, int& info);

    // DGEBRD - reduce a general real M-by-N matrix A to upper or
    // lower bidiagonal form B by an orthogonal transformation
    void F77_NAME(dgebrd)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* d, double* e, double* tauq,
			  double* taup, double* work, const int& lwork,
			  int& info);

    // DGECON - estimate the reciprocal of the condition number of a
    // general real matrix A, in either the 1-norm or the
    // infinity-norm, using the LU factorization computed by DGETRF
    void F77_NAME(dgecon)(const char& norm, const int& n,
			  const double* a, const int& lda,
			  const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DGEEQU - compute row and column scalings intended to equilibrate
    // an M-by-N matrix A and reduce its condition number
    void F77_NAME(dgeequ)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* r, double* c,
			  double* rowcnd, double* colcnd,
			  double* amax, int& info);

    // DGEES - compute for an N-by-N real nonsymmetric matrix A, the
    // eigenvalues, the real Schur form T, and, optionally, the matrix
    // of Schur vectors Z
    void F77_NAME(dgees)(const char& jobvs, const char& sort,
			 int (*select)(const double&, const double&),
			 const int& n, double* a, const int& lda,
			 int* sdim, double* wr, double* wi,
			 double* vs, const int& ldvs,
			 double* work, const int& lwork, int* bwork,
			 int& info);

    // DGEESX - compute for an N-by-N real nonsymmetric matrix A, the
    // eigenvalues, the real Schur form T, and, optionally, the matrix
    // of Schur vectors Z
    void F77_NAME(dgeesx)(const char& jobvs, const char& sort,
			  int (*select)(const double&, const double&),
			  const char& sense, const int& n, double* a,
			  const int& lda, int& sdim,
			  double* wr, double* wi,
			  double* vs, const int& ldvs,
			  double& rconde, double& rcondv,
			  double* work, const int& lwork,
			  int* iwork, const int& liwork,
			  int* bwork, int& info);

    // DGEEV - compute for an N-by-N real nonsymmetric matrix A, the
    // eigenvalues and, optionally, the left and/or right eigenvectors
    void F77_NAME(dgeev)(const char& jobvl, const char& jobvr,
			 const int& n, double* a, const int& lda,
			 double* wr, double* wi,
			 double* vl, const int& ldvl,
			 double* vr, const int& ldvr,
			 double* work, const int& lwork, int& info);

    // DGEEVX - compute for an N-by-N real nonsymmetric matrix A, the
    // eigenvalues and, optionally, the left and/or right eigenvectors
    void F77_NAME(dgeevx)(const char& balanc, const char& jobvl,
			  const char& jobvr, const char& sense,
			  const int& n, double* a, const int& lda,
			  double* wr, double* wi,
			  double* vl, const int& ldvl,
			  double* vr, const int& ldvr,
			  int* ilo, int* ihi,
			  double* scale, double* abnrm, 
			  double* rconde, double* rcondv,
			  double* work, const int& lwork, int* iwork,
			  int& info);

    // DGEGS - compute for a pair of N-by-N real nonsymmetric
    // matrices A, B
    void F77_NAME(dgegs)(const char& jobvsl, const char& jobvsr,
			 const int& n, double* a, const int& lda,
			 double* b, const int& ldb,
			 double* alphar, double* alphai,
			 const double& beta,
			 double* vsl, const int& ldvsl,
			 double* vsr, const int& ldvsr,
			 double* work, const int& lwork, int& info);

    // DGEGV - compute for a pair of n-by-n real nonsymmetric
    // matrices A and B, the generalized eigenvalues (alphar +/-
    // alphai*i, beta);, and optionally, the left and/or right
    // generalized eigenvectors (VL and VR);
    void F77_NAME(dgegv)(const char& jobvl, const char& jobvr,
			 const int& n, double* a, const int& lda,
			 double* b, const int& ldb,
			 double* alphar, double* alphai,
			 const double& beta, double* vl, const int& ldvl,
			 double* vr, const int& ldvr,
			 double* work, const int& lwork, int& info);
    
    // DGEHD2 - reduce a real general matrix A to upper Hessenberg
    // form H by an orthogonal similarity transformation
    void F77_NAME(dgehd2)(const int& n, const int& ilo, const int& ihi,
			  double* a, const int& lda, double* tau,
			  double* work, int& info);

    // DGEHRD - reduce a real general matrix A to upper Hessenberg
    // form H by an orthogonal similarity transformation
    void F77_NAME(dgehrd)(const int& n, const int& ilo, const int& ihi,
			  double* a, const int& lda, double* tau,
			  double* work, const int& lwork, int& info);

    // DGELQ2 - compute an LQ factorization of a real m by n matrix A
    void F77_NAME(dgelq2)(const int& m, const int& n,
			  double* a, const int& lda, double* tau,
			  double* work, int& info);

    // DGELQF - compute an LQ factorization of a real M-by-N matrix A
    void F77_NAME(dgelqf)(const int& m, const int& n,
			  double* a, const int& lda, double* tau,
			  double* work, const int& lwork, int& info);

    // DGELS - solve overdetermined or underdetermined real linear
    // systems involving an M-by-N matrix A, or its transpose, using a
    // QR or LQ factorization of A
    void F77_NAME(dgels)(const char& trans, const int& m,
			 const int& n, const int& nrhs,
			 double* a, const int& lda,
			 double* b, const int& ldb,
			 double* work, const int& lwork, int& info);

    // DGELSS - compute the minimum norm solution to a real linear
    // least squares problem
    void F77_NAME(dgelss)(const int& m, const int& n, const int& nrhs,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  double* s, double* rcond, int& rank,
			  double* work, const int& lwork, int& info);

    // DGELSX - compute the minimum-norm solution to a real linear
    // least squares problem
    void F77_NAME(dgelsx)(const int& m, const int& n, const int& nrhs,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  int* jpvt, double* rcond, int& rank,
			  double* work, int& info);

    // DGEQL2 - compute a QL factorization of a real m by n matrix A
    void F77_NAME(dgeql2)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* tau, double* work, int& info);

    // DGEQLF - compute a QL factorization of a real M-by-N matrix A
    void F77_NAME(dgeqlf)(const int& m, const int& n,
			  double* a, const int& lda, double* tau,
			  double* work, const int& lwork, int& info);

    // DGEQP3 - compute a QR factorization with column pivoting of a
    // real M-by-N matrix A using level 3 BLAS
    void F77_NAME(dgeqp3)(const int& m, const int& n,
			  double* a, const int& lda, int* jpvt,
			  double* tau, double* work, const int& lwork,
			  int& info);

    // DGEQPF - compute a QR factorization with column pivoting of a
    // real M-by-N matrix A
    void F77_NAME(dgeqpf)(const int& m, const int& n,
			  double* a, const int& lda, int* jpvt,
			  double* tau, double* work, int& info);

    // DGEQR2 - compute a QR factorization of a real m by n matrix A
    void F77_NAME(dgeqr2)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* tau, double* work, int& info);

    // DGEQRF - compute a QR factorization of a real M-by-N matrix A
    void F77_NAME(dgeqrf)(const int& m, const int& n,
			  double* a, const int& lda, double* tau,
			  double* work, const int& lwork, int& info);

    // DGERFS - improve the computed solution to a system of linear
    // equations and provides error bounds and backward error
    // estimates for the solution
    void F77_NAME(dgerfs)(const char& trans, const int& n, const int& nrhs,
			  double* a, const int& lda,
			  double* af, const int& ldaf, int* ipiv,
			  double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DGERQ2 - compute an RQ factorization of a real m by n matrix A
    void F77_NAME(dgerq2)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* tau, double* work, int& info);

    // DGERQF - compute an RQ factorization of a real M-by-N matrix A
    void F77_NAME(dgerqf)(const int& m, const int& n,
			  double* a, const int& lda, double* tau,
			  double* work, const int& lwork, int& info);

    // DGESV - compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dgesv)(const int& n, const int& nrhs,
			 double* a, const int& lda, int* ipiv,
			 double* b, const int& ldb, int& info);

    // DGESVD - compute the singular value decomposition (SVD); of a
    // real M-by-N matrix A, optionally computing the left and/or
    // right singular vectors
    void F77_NAME(dgesvd)(const char& jobu, const char& jobvt,
			  const int& m, const int& n,
			  double* a, const int& lda, double* s,
			  double* u, const int& ldu,
			  double* vt, const int& ldvt,
			  double* work, const int& lwork, int& info);

    // DGESVX - use the LU factorization to compute the solution to a
    // real system of linear equations  A * X = B,
    void F77_NAME(dgesvx)(const int& fact, const char& trans,
			  const int& n, const int& nrhs,
			  double* a, const int& lda,
			  double* af, const int& ldaf, int* ipiv,
			  char *equed, double* r, double* c,
			  double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* rcond, double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DGETF2 - compute an LU factorization of a general m-by-n
    // matrix A using partial pivoting with row interchanges
    void F77_NAME(dgetf2)(const int& m, const int& n,
			  double* a, const int& lda, int* ipiv,
			  int& info);

    // DGETRF - compute an LU factorization of a general M-by-N
    // matrix A using partial pivoting with row interchanges
    void F77_NAME(dgetrf)(const int& m, const int& n,
			  double* a, const int& lda, int* ipiv,
			  int& info);

    // DGETRI - compute the inverse of a matrix using the LU
    // factorization computed by DGETRF
    void F77_NAME(dgetri)(const int& n, double* a, const int& lda,
			  int* ipiv, double* work, const int& lwork,
			  int& info);

    // DGETRS - solve a system of linear equations  A * X = B or A' *
    // X = B with a general N-by-N matrix A using the LU factorization
    // computed by DGETRF
    void F77_NAME(dgetrs)(const char& trans, const int& n, const int& nrhs,
			  const double* a, const int& lda,
			  const int* ipiv,
			  double* b, const int& ldb, int& info);

    // DGGBAK - form the right or left eigenvectors of a real
    // generalized eigenvalue problem A*x = lambda*B*x, by backward
    // transformation on the computed eigenvectors of the balanced
    // pair of matrices output by DGGBAL
    void F77_NAME(dggbak)(const char& job, const char& side,
			  const int& n, const int& ilo, const int& ihi,
			  double* lscale, double* rscale, const int& m,
			  double* v, const int& ldv, int& info);

    // DGGBAL - balance a pair of general real matrices (A,B);
    void F77_NAME(dggbal)(const char& job, const int& n,
			  double* a, const int& lda,
			  double* b, const int& ldb, int* ilo, int* ihi,
			  double* lscale, double* rscale,
			  double* work, int& info);

    // DGGGLM - solve a general Gauss-Markov linear model (GLM); problem
    void F77_NAME(dggglm)(const int& n, const int& m, const int& p,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  double* d, double* x, double* y,
			  double* work, const int& lwork, int& info);

    // DGGHRD - reduce a pair of real matrices (A,B); to generalized
    // upper Hessenberg form using orthogonal transformations, where A
    // is a general matrix and B is upper triangular
    void F77_NAME(dgghrd)(const char& compq, const char& compz, const int& n,
			  const int& ilo, const int& ihi,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  double* q, const int& ldq,
			  double* z, const int& ldz, int& info);
    
    // DGGLSE - solve the linear equality-constrained least squares
    // (LSE); problem
    void F77_NAME(dgglse)(const int& m, const int& n, const int& p,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  double* c, double* d, double* x,
			  double* work, const int& lwork, int& info);

    // DGGQRF - compute a generalized QR factorization of an N-by-M
    // matrix A and an N-by-P matrix B
    void F77_NAME(dggqrf)(const int& n, const int& m, const int& p,
			  double* a, const int& lda, double* taua,
			  double* b, const int& ldb, double* taub,
			  double* work, const int& lwork, int& info);

    // DGGRQF - compute a generalized RQ factorization of an M-by-N
    // matrix A and a P-by-N matrix B
    void F77_NAME(dggrqf)(const int& m, const int& p, const int& n,
			  double* a, const int& lda, double* taua,
			  double* b, const int& ldb, double* taub,
			  double* work, const int& lwork, int& info);

    // DGGSVD - compute the generalized singular value decomposition
    // (GSVD); of an M-by-N real matrix A and P-by-N real matrix B
    void F77_NAME(dggsvd)(const char& jobu, const char& jobv, const char& jobq,
			  const int& m, const int& n, const int& p,
			  const int& k, const int& l,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  const double& alpha, const double& beta,
			  double* u, const int& ldu,
			  double* v, const int& ldv,
			  double* q, const int& ldq,
			  double* work, int* iwork, int& info);

    // DGGSVP - compute orthogonal matrices U, V and Q such that
    // N-K-L K L  U'*A*Q = K ( 0 A12 A13 ); if M-K-L >= 0
    void F77_NAME(dggsvp)(const char& jobu, const char& jobv, const char& jobq,
			  const int& m, const int& p, const int& n,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  const double& tola, const double& tolb,
			  const int& k, const int& l,
			  double* u, const int& ldu,
			  double* v, const int& ldv,
			  double* q, const int& ldq,
			  int* iwork, double* tau, double* work, int& info);

    // DGTCON - estimate the reciprocal of the condition number of a
    // real tridiagonal matrix A using the LU factorization as
    // computed by DGTTRF
    void F77_NAME(dgtcon)(const char& norm, const int& n,
			  double* dl, double* d, double* du, double* du2,
			  int* ipiv, const double& anorm, double* rcond,
			  double* work, int* iwork, int& info);
    
    // DGTRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is tridiagonal, and
    // provides error bounds and backward error estimates for the
    // solution
    void F77_NAME(dgtrfs)(const char& trans, const int& n, const int& nrhs,
			  double* dl, double* d, double* du, double* dlf,
			  double* df, double* duf, double* du2,
			  int* ipiv, double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DGTSV - solve the equation   A*X = B,
    void F77_NAME(dgtsv)(const int& n, const int& nrhs,
			 double* dl, double* d, double* du,
			 double* b, const int& ldb, int& info);

    // DGTSVX - use the LU factorization to compute the solution to a
    // real system of linear equations A * X = B or A**T * X = B,
    void F77_NAME(dgtsvx)(const int& fact, const char& trans,
			  const int& n, const int& nrhs,
			  double* dl, double* d, double* du,
			  double* dlf, double* df, double* duf,
			  double* du2, int* ipiv,
			  double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* rcond, double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DGTTRF - compute an LU factorization of a real tridiagonal
    // matrix A using elimination with partial pivoting and row
    // interchanges
    void F77_NAME(dgttrf)(const int& n, double* dl, double* d,
			  double* du, double* du2, int* ipiv, int& info);

    // DGTTRS - solve one of the systems of equations  A*X = B or
    // A'*X = B,
    void F77_NAME(dgttrs)(const char& trans, const int& n, const int& nrhs,
			  double* dl, double* d, double* du, double* du2,
			  int* ipiv, double* b, const int& ldb, int& info);

    // DHGEQZ - implement a single-/double-shift version of the QZ
    // method for finding the generalized eigenvalues
    // w(j);=(ALPHAR(j); + i*ALPHAI(j););/BETAR(j); of the equation
    // det( A - w(i); B ); = 0  In addition, the pair A,B may be
    // reduced to generalized Schur form
    void F77_NAME(dhgeqz)(const char& job, const char& compq, const char& compz,
			  const int& n, const int &ILO, const int& IHI,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  double* alphar, double* alphai, const double& beta,
			  double* q, const int& ldq,
			  double* z, const int& ldz,
			  double* work, const int& lwork, int& info);

    // DHSEIN - use inverse iteration to find specified right and/or
    // left eigenvectors of a real upper Hessenberg matrix H
    void F77_NAME(dhsein)(const char& side, const char& eigsrc,
			  const char& initv, int* select,
			  const int& n, double* h, const int& ldh,
			  double* wr, double* wi,
			  double* vl, const int& ldvl,
			  double* vr, const int& ldvr,
			  const int& mm, int* m, double* work,
			  int* ifaill, int* ifailr, int& info);

    // DHSEQR - compute the eigenvalues of a real upper Hessenberg
    // matrix H and, optionally, the matrices T and Z from the Schur
    // decomposition H = Z T Z**T, where T is an upper
    // quasi-triangular matrix (the Schur form);, and Z is the
    // orthogonal matrix of Schur vectors
    void F77_NAME(dhseqr)(const char& job, const char& compz, const int& n,
			  const int& ilo, const int& ihi,
			  double* h, const int* ldh,
			  double* wr, double* wi,
			  double* z, const int* ldz,
			  double* work, const int& lwork, int& info);

    // DLABAD - take as input the values computed by SLAMCH for
    // underflow and overflow, and returns the square root of each of
    // these values if the log of LARGE is sufficiently large
    void F77_NAME(dlabad)(double* small, double* large);

    // DLABRD - reduce the first NB rows and columns of a real
    // general m by n matrix A to upper or lower bidiagonal form by an
    // orthogonal transformation Q' * A * P, and returns the matrices
    // X and Y which are needed to apply the transformation to the
    // unreduced part of A
    void F77_NAME(dlabrd)(const int& m, const int& n, const int& nb,
			  double* a, const int& lda,
			  double* d, double* e,
			  double* tauq, double* taup,
			  double* x, const int& ldx,
			  double* y, const int& ldy);

    // DLACON - estimate the 1-norm of a square, real matrix A
    void F77_NAME(dlacon)(const int& n, double* v, double* x,
			  int* isgn, double* est, int* kase);

    // DLACPY - copy all or part of a two-dimensional matrix A to
    // another matrix B
    void F77_NAME(dlacpy)(const char& uplo, const int& m, const int& n,
			  const double* a, const int& lda,
			  double* b, const int& ldb);

    // DLADIV - perform complex division in real arithmetic 
    void F77_NAME(dladiv)(const double& a, const double& b,
			  const double& c, const double& d,
			  double& p, double& q);

    // DLAE2 - compute the eigenvalues of a 2-by-2 symmetric matrix
    // [ A B ]  [ B C ]
    void F77_NAME(dlae2)(const double& a, const double& b, const double& c,
			 double& rt1, double& rt2);

    // DLAEBZ - contain the iteration loops which compute and use the
    // function N(w);, which is the count of eigenvalues of a
    // symmetric tridiagonal matrix T less than or equal to its
    // argument w 
    void F77_NAME(dlaebz)(const int& ijob, const int& nitmax, const int& n,
			  const int& mmax, const int& minp, const int& nbmin,
			  const double& abstol, const double& reltol,
			  const double& pivmin, double* d, double* e,
			  double* e2, int* nval, double* ab, double* c,
			  int* mout, int* nab, double* work, int* iwork,
			  int& info);

    // DLAED0 - compute all eigenvalues and corresponding
    // eigenvectors of a symmetric tridiagonal matrix using the divide
    // and conquer method
    void F77_NAME(dlaed0)(const int& icompq, const int& qsiz, const int& n,
			  double* d, double* e, double* q, const int& ldq,
			  double* qstore, const int& ldqs,
			  double* work, int* iwork, int& info);

    // DLAED1 - compute the updated eigensystem of a diagonal matrix
    // after modification by a rank-one symmetric matrix
    void F77_NAME(dlaed1)(const int& n, double* d, double* q, const int& ldq,
			  int* indxq, const double& rho, const int& cutpnt,
			  double* work, int* iwork, int& info);

    // DLAED2 - merge the two sets of eigenvalues together into a
    // single sorted set
    void F77_NAME(dlaed2)(const int& k, const int& n, double* d,
			  double* q, const int& ldq, int* indxq,
			  double& rho, const int& cutpnt, double* z,
			  double* dlamda, double* q2, const int &ldq2,
			  int* indxc, int* w, int* indxp, int* indx,
			  int* coltyp, int& info);

    // DLAED3 - find the roots of the secular equation, as defined by
    // the values in double* d, W, and RHO, between KSTART and KSTOP
    void F77_NAME(dlaed3)(const int& k, const int& kstart,
			  const int &kstop, const int& n,
			  double* d, double* q, const int& ldq,
			  const double& rho, const int& cutpnt,
			  double* dlamda, int* q2, const int& ldq2,
			  int* indxc, int* ctot, double* w,
			  double* s, const int& lds, int& info);

    // DLAED4 - subroutine computes the I-th updated eigenvalue of a
    // symmetric rank-one modification to a diagonal matrix whose
    // elements are given in the array d, and that   D(i); < D(j); for
    // i < j  and that RHO > 0
    void F77_NAME(dlaed4)(const int& n, const int& i, const double* d,
			  const double* z, const double* delta,
			  const double& rho, double& dlam, int& info);

    // DLAED5 - subroutine computes the I-th eigenvalue of a
    // symmetric rank-one modification of a 2-by-2 diagonal matrix
    // diag( D ); + RHO  The diagonal elements in the array D are
    // assumed to satisfy   D(i); < D(j); for i < j 
    void F77_NAME(dlaed5)(const int& i, const double* d, const double* z,
			  double* delta, const double& rho, double& dlam);

    // DLAED6 - compute the positive or negative root (closest to the
    // origin); of  z(1); z(2); z(3); f(x); = rho + --------- +
    // ---------- + ---------  d(1);-x d(2);-x d(3);-x  It is assumed
    // that   if ORGATI = .true 
    void F77_NAME(dlaed6)(const int& kniter, const int& orgati,
			  const double& rho, const double* d,
			  const double* z, const double& finit,
			  double* tau, int& info);

    // DLAED7 - compute the updated eigensystem of a diagonal matrix
    // after modification by a rank-one symmetric matrix
    void F77_NAME(dlaed7)(const int& icompq, const int& n,
			  const int& qsiz, const int& tlvls,
			  const int& curlvl, const int& curpbm,
			  double* d, double* q, const int& ldq,
			  int* indxq, const double& rho, const int& cutpnt,
			  double* qstore, double* qptr, const int* prmptr,
			  const int* perm, const int* givptr,
			  const int* givcol, const double* givnum,
			  double* work, int* iwork, int& info);

    // DLAED8 - merge the two sets of eigenvalues together into a
    // single sorted set
    void F77_NAME(dlaed8)(const int& icompq, const int& k,
			  const int& n, const int& qsiz,
			  double* d, double* q, const int& ldq,
			  const int* indxq, double& rho,
			  const int& cutpnt, const double* z,
			  double* dlamda, double* q2, const int& ldq2,
			  double* w, int* perm, int& givptr,
			  int* givcol, double* givnum, int* indxp,
			  int* indx, int& info);

    // DLAED9 - find the roots of the secular equation, as defined by
    // the values in double* d, Z, and RHO, between KSTART and KSTOP
    void F77_NAME(dlaed9)(const int& k, const int& kstart, const int& kstop,
			  const int& n, double* d, double* q, const int& ldq,
			  const double& rho, const double* dlamda,
			  const double* w, double* s, const int& lds, int& info);

    // DLAEDA - compute the Z vector corresponding to the merge step
    // in the CURLVLth step of the merge process with TLVLS steps for
    // the CURPBMth problem
    void F77_NAME(dlaeda)(const int& n, const int& tlvls, const int& curlvl,
			  const int& curpbm, const int* prmptr, const int* perm,
			  const int* givptr, const int* givcol,
			  const double* givnum, const double* q,
			  const int* qptr, double* z, double* ztemp, int& info);

    // DLAEIN - use inverse iteration to find a right or left
    // eigenvector corresponding to the eigenvalue (WR,WI); of a real
    // upper Hessenberg matrix H
    void F77_NAME(dlaein)(const int& rightv, const int& noinit, const int& n,
			  const double* h, const int& ldh,
			  const double* wr, const double* wi,
			  double* vr, double* vi,
			  double* b, const int& ldb, double* work,
			  const double& eps3, const double& smlnum,
			  const double& bignum, int& info);

    // DLAEV2 - compute the eigendecomposition of a 2-by-2 symmetric
    // matrix  [ A B ]  [ B C ]
    void F77_NAME(dlaev2)(const double& a, const double& b, const double& c, 
			  double& rt1, double& rt2, double& cs1, double &sn1);

    // DLAEXC - swap adjacent diagonal blocks T11 and T22 of order 1
    // or 2 in an upper quasi-triangular matrix T by an orthogonal
    // similarity transformation
    void F77_NAME(dlaexc)(const int& wantq, const int& n,
			  double* t, const int& ldt,
			  double* q, const int& ldq,
			  const int& j1, const int& n1, const int& n2,
			  double* work, int& info);

    // DLAG2 - compute the eigenvalues of a 2 x 2 generalized
    // eigenvalue problem A - w B, with scaling as necessary to avoid
    // over-/underflow
    void F77_NAME(dlag2)(const double* a, const int& lda,
			 const double* b, const int& ldb,
			 const double& safmin,
			 double& scale1, double& scale2,
			 double& wr1, double& wr2, double& wi);

    // DLAGS2 - compute 2-by-2 orthogonal matrices U, V and Q, such
    // that if ( UPPER ); then   U'*A*Q = U'*( A1 A2 );*Q = ( x 0 );
    // ( 0 A3 ); ( x x ); and  V'*B*Q = V'*( B1 B2 );*Q = ( x 0 );  (
    // 0 B3 ); ( x x );  or if ( .NOT.UPPER ); then   U'*A*Q = U'*( A1
    // 0 );*Q = ( x x );  ( A2 A3 ); ( 0 x ); and  V'*B*Q = V'*( B1 0
    // );*Q = ( x x );  ( B2 B3 ); ( 0 x );  The rows of the
    // transformed A and B are parallel, where   U = ( CSU SNU );, V =
    // ( CSV SNV );, Q = ( CSQ SNQ );  ( -SNU CSU ); ( -SNV CSV ); (
    // -SNQ CSQ );  Z' denotes the transpose of Z
    void F77_NAME(dlags2)(const int& upper,
			  const double& a1, const double& a2, const double& a3,
			  const double& b1, const double& b2, const double& b3,
			  double& csu, double& snu,
			  double& csv, double& snv,
			  double &csq, double &snq);

    // DLAGTF - factorize the matrix (T - lambda*I);, where T is an n
    // by n tridiagonal matrix and lambda is a scalar, as   T -
    // lambda*I = PLU,
    void F77_NAME(dlagtf)(const int& n, double* a, const double& lambda,
			  double* b, double* c, const double &tol,
			  double* d, int* in, int& info);

    // DLAGTM - perform a matrix-vector product of the form   B :=
    // alpha * A * X + beta * B  where A is a tridiagonal matrix of
    // order N, B and X are N by NRHS matrices, and alpha and beta are
    // real scalars, each of which may be 0., 1., or -1
    void F77_NAME(dlagtm)(const char& trans, const int& n, const int& nrhs,
			  const double& alpha, const double* dl,
			  const double* d, const double* du,
			  const double* x, const int& ldx, const double& beta,
			  double* b, const int& ldb);

    // DLAGTS - may be used to solve one of the systems of equations
    // (T - lambda*I);*x = y or (T - lambda*I);'*x = y,
    void F77_NAME(dlagts)(const int& job, const int& n,
			  const double* a, const double* b,
			  const double* c, const double* d,
			  const int* in, double* y, double& tol, int& info);

    // DLAHQR - an auxiliary routine called by DHSEQR to update the
    // eigenvalues and Schur decomposition already computed by DHSEQR,
    // by dealing with the Hessenberg submatrix in rows and columns
    // ILO to IHI
    void F77_NAME(dlahqr)(const int& wantt, const int& wantz, const int& n,
			  const int& ilo, const int& ihi,
			  double* H, const int& ldh, double* wr, double* wi,
			  const int& iloz, const int& ihiz,
			  double* z, const int& ldz, int& info);

    // DLAHRD - reduce the first NB columns of a real general
    // n-by-(n-k+1); matrix A so that elements below the k-th
    // subdiagonal are zero
    void F77_NAME(dlahrd)(const int& n, const int& k, const int& nb,
			  double* a, const int& lda,
			  double* tau, double* t, const int& ldt,
			  double* y, const int& ldy);

    // DLAIC1 - apply one step of incremental condition estimation in
    // its simplest version
    void F77_NAME(dlaic1)(const int& job, const int& j, const double* x,
			  const double& sest, const double* w,
			  const double& gamma, double& sestpr,
			  double& s, double& c);

    // DLALN2 - solve a system of the form (ca A - w D ); X = s B or
    // (ca A' - w D); X = s B with possible scaling ("s"); and
    // perturbation of A
    void F77_NAME(dlaln2)(const int& ltrans, const int& na, const int& nw,
			  const double& smin, const double& ca,
			  const double* a, const int& lda,
			  const double& d1, const double& d2,
			  const double* b, const int& ldb,
			  const double* wr, const double* wi,
			  double* x, const int& ldx, double& scale,
			  double& xnorm, int& info);

    // DLAMCH - determine double precision machine parameters
    double F77_NAME(dlamch)(const char& cmach);

    // DLAMRG - will create a permutation list which will merge the
    // elements of A (which is composed of two independently sorted
    // sets); into a single set which is sorted in ascending order
    void F77_NAME(dlamrg)(const int& n1, const int& n2, const double* a,
			  const int& dtrd1, const int& dtrd2, int* index);

    // DLANGB - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of an n by n band matrix A, with kl sub-diagonals and ku
    // super-diagonals
    double F77_NAME(dlangb)(const char& norm, const int& n,
			    const int& kl, const int& ku, const double* ab,
			    const int& ldab, double* work);

    // DLANGE - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a real matrix A
    double F77_NAME(dlange)(const char& norm, const int& m, const int& n,
			    const double* a, const int& lda, double* work);

    // DLANGT - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a real tridiagonal matrix A
    double F77_NAME(dlangt)(const char& norm, const int& n,
			    const double* dl, const double* d,
			    const double* du);

    // DLANHS - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a Hessenberg matrix A
    double F77_NAME(dlanhs)(const char& norm, const int& n,
			    const double* a, const int& lda, double* work);

    // DLANSB - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of an n by n symmetric band matrix A, with k
    // super-diagonals
    double F77_NAME(dlansb)(const char& norm, const char& uplo,
			    const int& n, const int& k,
			    const double* ab, const int& ldab,
			    double* work);

    // DLANSP - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a real symmetric matrix A, supplied in packed form
    double F77_NAME(dlansp)(const char& norm, const char& uplo,
			    const int& n, const double* ap, double* work);

    // DLANST - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a real symmetric tridiagonal matrix A
    double F77_NAME(dlanst)(const char& norm, const int& n,
			    const double* d, const double* e);

    // DLANSY - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a real symmetric matrix A
    double F77_NAME(dlansy)(const char& norm, const char& uplo,
			    const int& n, const double* a,
			    const int& lda, double* work);

    // DLANTB - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of an n by n triangular band matrix A, with ( k + 1 );
    // diagonals
    double F77_NAME(dlantb)(const char& norm, const char& uplo,
			    const char& diag, const int& n, const int& k,
			    const double* ab, const int& ldab,
			    double* work);

    // DLANTP - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a triangular matrix A, supplied in packed form
    double F77_NAME(dlantp)(const char& norm, const char& uplo,
			    const char& diag, const int& n,
			    const double* ap, double* work);

    // DLANTR - return the value of the one norm, or the Frobenius
    // norm, or the infinity norm, or the element of largest absolute
    // value of a trapezoidal or triangular matrix A
    double F77_NAME(dlantr)(const char& norm, const char& uplo,
			    const char& diag, const int& m, const int& n,
			    const double* a, const int& lda, double* work);

    // DLANV2 - compute the Schur factorization of a real 2-by-2
    // nonsymmetric matrix in standard form
    void F77_NAME(dlanv2)(double& a, double& b, double& c, double& d,
			  double& rt1r, double& rt1i,
			  double& rt2r, double& rt2i,
			  double& cs, double &sn);

    // DLAPLL - two column vectors X and Y, let A = ( X Y );
    void F77_NAME(dlapll)(const int& n, double* x, const int& incx,
			  double* y, const int& incy, double& ssmin);

    // DLAPMT - rearrange the columns of the M by N matrix X as
    // specified by the permutation K(1);,K(2);,...,K(N); of the
    // integers 1,...,N
    void F77_NAME(dlapmt)(const int& forwrd, const int& m,
			  const int& n, double* x, const int& ldx,
			  const int* k);

    // DLAPY2 - return sqrt(x**2+y**2);, taking care not to cause
    // unnecessary overflow
    double F77_NAME(dlapy2)(const double& x, const double& y);

    // DLAPY3 - return sqrt(x**2+y**2+z**2);, taking care not to
    // cause unnecessary overflow
    double F77_NAME(dlapy3)(const double& x, const double& y,
			    const double& z);

    // DLAQGB - equilibrate a general M by N band matrix A with KL
    // subdiagonals and KU superdiagonals using the row and scaling
    // factors in the vectors R and C
    void F77_NAME(dlaqgb)(const int& m, const int& n,
			  const int& kl, const int& ku,
			  double* ab, const int& ldab,
			  double* r, double* c,
			  double& rowcnd, double& colcnd,
			  const double& amax, char& equed);

    // DLAQGE - equilibrate a general M by N matrix A using the row
    // and scaling factors in the vectors R and C
    void F77_NAME(dlaqge)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* r, double* c,
			  double& rowcnd, double& colcnd,
			  const double& amax, char& equed);

    // DLAQSB - equilibrate a symmetric band matrix A using the
    // scaling factors in the vector S
    void F77_NAME(dlaqsb)(const char& uplo, const int& n, const int& kd,
			  double* ab, const int& ldab,
			  const double* s, const double& scond,
			  const double& amax, char& equed);

    // DLAQSP - equilibrate a symmetric matrix A using the scaling
    // factors in the vector S
    void F77_NAME(dlaqsp)(const char& uplo, const int& n,
			  double* ap, const double* s, const double& scond,
			  const double& amax, int& equed);

    // DLAQSY - equilibrate a symmetric matrix A using the scaling
    // factors in the vector S
    void F77_NAME(dlaqsy)(const char& uplo, const int& n,
			  double* a, const int& lda,
			  const double* s, const double& scond, 
			  const double& amax, int& equed);

    // DLAQTR - solve the real quasi-triangular system   op(T);*p =
    // scale*c, if LREAL = .TRUE
    void F77_NAME(dlaqtr)(const int& ltran, const int& lreal, const int& n,
			  const double* t, const int& ldt,
			  const double* b, const double& w,
			  double& scale, double* x, double* work,
			  int& info);

    // DLAR2V - apply a vector of real plane rotations from both
    // sides to a sequence of 2-by-2 real symmetric matrices, defined
    // by the elements of the vectors x, y and z 
    void F77_NAME(dlar2v)(const int& n, double* x, double* y,
			  double* z, const int& incx,
			  const double* c, const double* s,
			  const int& incc);

    // DLARF - apply a real elementary reflector H to a real m by n
    // matrix C, from either the left or the right
    void F77_NAME(dlarf)(const char& side, const int& m, const int& n,
			 const double* v, const int& incv,
			 const double* tau, double* c, const int& ldc,
			 double* work);

    // DLARFB - apply a real block reflector H or its transpose H'
    // to a real m by n matrix C, from either the left or the right
    void F77_NAME(dlarfb)(const char& side, const char& trans,
			  const char& direct, const char& storev,
			  const int& m, const int& n, const int& k,
			  const double* v, const int& ldv,
			  const double* t, const int& ldt,
			  double* c, const int& ldc,
			  double* work, const int& lwork);

    // DLARFG - generate a real elementary reflector H of order n,
    // such that   H * ( alpha ); = ( beta );, H' * H = I
    void F77_NAME(dlarfg)(const int& n, const double& alpha,
			  double* x, const int& incx, double& tau);

    // DLARFT - form the triangular factor T of a real block
    // reflector H of order n, which is defined as a product of k
    // elementary reflectors
    void F77_NAME(dlarft)(const char& direct, const char& storev,
			  const int& n, const int& k,
			  double* v, const int& ldv, const double* tau,
			  double* t, const int& ldt);

    // DLARFX - apply a real elementary reflector H to a real m by n
    // matrix C, from either the left or the right
    void F77_NAME(dlarfx)(const char& side, const int& m, const int& n,
			  const double* v, const double& tau,
			  double* c, const int& ldc, double* work);

    // DLARGV - generate a vector of real plane rotations, determined
    // by elements of the real vectors x and y
    void F77_NAME(dlargv)(const int& n, double* x, const int& incx,
			  double* y, const int& incy,
			  double* c, const int& incc);

    // DLARNV - return a vector of n random real numbers from a
    // uniform or normal distribution
    void F77_NAME(dlarnv)(const int& idist, int* iseed, const int& n,
			  double* x);

    // DLARTG - generate a plane rotation so that   [ CS SN ] 
    void F77_NAME(dlartg)(const double& f, const double& g, double& cs,
			  double& sn, double &r);

    // DLARTV - apply a vector of real plane rotations to elements of
    // the real vectors x and y
    void F77_NAME(dlartv)(const int& n, double* x, const int& incx,
			  double* y, const int& incy,
			  const double* c, const double* s,
			  const int& incc);

    // DLARUV - return a vector of n random real numbers from a
    // uniform (0,1);
    void F77_NAME(dlaruv)(int* iseed, const int& n, double* x);

    // DLAS2 - compute the singular values of the 2-by-2 matrix
    // [ F G ]  [ 0 H ]
    void F77_NAME(dlas2)(const double& f, const double& g, const double& h,
			 double& ssmin, double& ssmax);

    // DLASCL - multiply the M by N real matrix A by the real scalar
    // CTO/CFROM
    void F77_NAME(dlascl)(const char& type,
			  const int& kl,const int& ku,
			  double& cfrom, double& cto,
			  const int& m, const int& n,
			  double* a, const int& lda, int& info);

    // DLASET - initialize an m-by-n matrix A to BETA on the diagonal
    // and ALPHA on the offdiagonals
    void F77_NAME(dlaset)(const char& uplo, const int& m, const int& n,
			  const double& alpha, const double& beta,
			  double* a, const int& lda);

    // DLASQ1 - DLASQ1 computes the singular values of a real N-by-N
    // bidiagonal  matrix with diagonal D and off-diagonal E
    void F77_NAME(dlasq1)(const int& n, double* d, double* e,
			  double* work, int& info);

    // DLASQ2 - DLASQ2 computes the singular values of a real N-by-N
    // unreduced  bidiagonal matrix with squared diagonal elements in
    // Q and  squared off-diagonal elements in E
    void F77_NAME(dlasq2)(const int& m, double* q, double* e,
			  double* qq, double* ee, const double& eps,
			  const double& tol2, const double& small2,
			  double& sup, int& kend, int& info);

    // DLASQ3 - DLASQ3 is the workhorse of the whole bidiagonal SVD
    // algorithm
    void F77_NAME(dlasq3)(int& n, double* q, double* e, double* qq,
			  double* ee, double& sup, double &sigma,
			  int& kend, int& off, int& iphase,
			  const int& iconv, const double& eps,
			  const double& tol2, const double& small2);

    // DLASQ4 - DLASQ4 estimates TAU, the smallest eigenvalue of a
    // matrix
    void F77_NAME(dlasq4)(const int& n, const double* q, const double* e,
			  double& tau, double& sup);

    // DLASR - perform the transformation   A := P*A, when SIDE = 'L'
    // or 'l' ( Left-hand side );   A := A*P', when SIDE = 'R' or 'r'
    // ( Right-hand side );  where A is an m by n real matrix and P is
    // an orthogonal matrix,
    void F77_NAME(dlasr)(const char& side, const char& pivot,
			 const char& direct,
			 const int& m, const int& n,
			 const double* c, const double* s,
			 double* a, const int& lda);

    // DLASRT - the numbers in D in increasing order (if ID = 'I');
    // or in decreasing order (if ID = 'D' );
    void F77_NAME(dlasrt)(const char& id, const int& n, double* d, int& info);

    // DLASSQ - return the values scl and smsq such that   ( scl**2
    // );*smsq = x( 1 );**2 +...+ x( n );**2 + ( scale**2 );*sumsq,
    void F77_NAME(dlassq)(const int& n, const double* x, const int& incx,
			  double& scale, double& sumsq);

    // DLASV2 - compute the singular value decomposition of a 2-by-2
    // triangular matrix  [ F G ]  [ 0 H ]
    void F77_NAME(dlasv2)(const double& f, const double& g, const double& h,
			  double& ssmin, double& ssmax,
			  double& snr, double& csr,
			  double& snl, double& csl);

    // DLASWP - perform a series of row interchanges on the matrix A
    void F77_NAME(dlaswp)(const int& n, double* a, const int& lda,
			  const int& k1, const int& k2,
			  const int* ipiv, const int& incx);

    // DLASY2 - solve for the N1 by N2 matrix double* x, 1 <= N1,N2 <= 2, in
    // op(TL);*X + ISGN*X*op(TR); = SCALE*B,
    void F77_NAME(dlasy2)(const int& ltranl, const int& ltranr,
			  const int& isgn, const int& n1, const int& n2,
			  const double* tl, const int& ldtl,
			  const double* tr, const int& ldtr,
			  const double* b, const int& ldb,
			  double& scale, double* x, const int& ldx,
			  double& xnorm, int& info);

    // DLASYF - compute a partial factorization of a real symmetric
    // matrix A using the Bunch-Kaufman diagonal pivoting method
    void F77_NAME(dlasyf)(const char& uplo, const int& n,
			  const int& nb, const int& kb,
			  double* a, const int& lda, int* ipiv,
			  double* w, const int& ldw, int& info);

    // DLATBS - solve one of the triangular systems   A *x = s*b or
    // A'*x = s*b  with scaling to prevent overflow, where A is an
    // upper or lower triangular band matrix
    void F77_NAME(dlatbs)(const char& uplo, const char& trans,
			  const char& diag, const char& normin,
			  const int& n, const int& kd,
			  const double* ab, const int& ldab,
			  double* x, double& scale, double* cnorm,
			  int& info);

    // DLATPS - solve one of the triangular systems   A *x = s*b or
    // A'*x = s*b  with scaling to prevent overflow, where A is an
    // upper or lower triangular matrix stored in packed form
    void F77_NAME(dlatps)(const char& uplo, const char& trans,
			  const char& diag, const char& normin,
			  const int& n, const double* ap,
			  double* x, double& scale, double* cnorm,
			  int& info);

    // DLATRD - reduce NB rows and columns of a real symmetric matrix
    // A to symmetric tridiagonal form by an orthogonal similarity
    // transformation Q' * A * Q, and returns the matrices V and W
    // which are needed to apply the transformation to the unreduced
    // part of A
    void F77_NAME(dlatrd)(const char& uplo, const int& n, const int& nb,
			  double* a, const int& lda,
			  double* e, double* tau,
			  double* w, const int& ldw);

    // DLATRS - solve one of the triangular systems   A *x = s*b or
    // A'*x = s*b  with scaling to prevent overflow
    void F77_NAME(dlatrs)(const char& uplo, const char& trans,
			  const char& diag, const char& normin,
			  const int& n, const double* a, const int& lda,
			  double* x, double& scale, double* cnorm,
			  int& info);

    // DLATZM - apply a Householder matrix generated by DTZRQF to a
    // matrix
    void F77_NAME(dlatzm)(const char& side, const int& m, const int& n,
			  const double* v, const int& incv,
			  const double* tau, double* c1, double* c2,
			  const int& ldc, double* work);

    // DLAUU2 - compute the product U * U' or L' * const int& l, where the
    // triangular factor U or L is stored in the upper or lower
    // triangular part of the array A
    void F77_NAME(dlauu2)(const char& uplo, const int& n,
			  double* a, const int& lda, int& info);

    // DLAUUM - compute the product U * U' or L' * L, where the
    // triangular factor U or L is stored in the upper or lower
    // triangular part of the array A
    void F77_NAME(dlauum)(const char& uplo, const int& n,
			  double* a, const int& lda, int& info);

    // DOPGTR - generate a real orthogonal matrix Q which is defined
    // as the product of n-1 elementary reflectors H(i); of order n,
    // as returned by DSPTRD using packed storage
    void F77_NAME(dopgtr)(const char& uplo, const int& n,
			  const double* ap, const double* tau,
			  double* q, const int& ldq,
			  double* work, int& info);

    // DOPMTR - overwrite the general real M-by-N matrix C with
    // SIDE = 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dopmtr)(const char& side, const char& uplo,
			  const char& trans, const int& m, const int& n,
			  const double* ap, const double* tau,
			  double* c, const int& ldc,
			  double* work, int& info);

    // DORG2L - generate an m by n real matrix Q with orthonormal
    // columns,
    void F77_NAME(dorg2l)(const int& m, const int& n, const int& k,
			  double* a, const int& lda,
			  const double* tau, double* work, int& info);

    // DORG2R - generate an m by n real matrix Q with orthonormal
    // columns,
    void F77_NAME(dorg2r)(const int& m, const int& n, const int& k,
			  double* a, const int& lda,
			  const double* tau, double* work, int& info);

    // DORGBR - generate one of the real orthogonal matrices Q or
    // P**T determined by DGEBRD when reducing a real matrix A to
    // bidiagonal form
    void F77_NAME(dorgbr)(const char& vect, const int& m,
			  const int& n, const int& k,
			  double* a, const int& lda,
			  const double* tau, double* work,
			  const int& lwork, int& info);

    // DORGHR - generate a real orthogonal matrix Q which is defined
    // as the product of IHI-ILO elementary reflectors of order N, as
    // returned by DGEHRD
    void F77_NAME(dorghr)(const int& n, const int& ilo, const int& ihi,
			  double* a, const int& lda, const double* tau,
			  double* work, const int& lwork, int& info);

    // DORGL2 - generate an m by n real matrix Q with orthonormal
    // rows,
    void F77_NAME(dorgl2)(const int& m, const int& n, const int& k,
			  double* a, const int& lda, const double* tau,
			  double* work, int& info);

    // DORGLQ - generate an M-by-N real matrix Q with orthonormal
    // rows,
    void F77_NAME(dorglq)(const int& m, const int& n, const int& k,
			  double* a, const int& lda,
			  const double* tau, double* work,
			  const int& lwork, int& info);

    // DORGQL - generate an M-by-N real matrix Q with orthonormal
    // columns,
    void F77_NAME(dorgql)(const int& m, const int& n, const int& k,
			  double* a, const int& lda,
			  const double* tau, double* work,
			  const int& lwork, int& info);

    // DORGQR - generate an M-by-N real matrix Q with orthonormal
    // columns,
    void F77_NAME(dorgqr)(const int& m, const int& n, const int& k,
			  double* a, const int& lda, const double* tau,
			  double* work, const int& lwork, int& info);

    // DORGR2 - generate an m by n real matrix Q with orthonormal
    // rows,
    void F77_NAME(dorgr2)(const int& m, const int& n, const int& k,
			  double* a, const int& lda, const double* tau,
			  double* work, int& info);

    // DORGRQ - generate an M-by-N real matrix Q with orthonormal
    // rows,
    void F77_NAME(dorgrq)(const int& m, const int& n, const int& k,
			  double* a, const int& lda, const double* tau,
			  double* work, const int& lwork, int& info);

    // DORGTR - generate a real orthogonal matrix Q which is defined
    // as the product of n-1 elementary reflectors of order const int& n, as
    // returned by DSYTRD
    void F77_NAME(dorgtr)(const char& uplo, const int& n,
			  double* a, const int& lda, const double* tau,
			  double* work, const int& lwork, int& info);

    // DORM2L - overwrite the general real m by n matrix C with   Q *
    // C if SIDE = 'L' and TRANS = 'N', or   Q'* C if SIDE = 'L' and
    // TRANS = 'T', or   C * Q if SIDE = 'R' and TRANS = 'N', or   C *
    // Q' if SIDE = 'R' and TRANS = 'T',
    void F77_NAME(dorm2l)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau,
			  double* c, const int& ldc,
			  double* work, int& info);

    // DORM2R - overwrite the general real m by n matrix C with   Q * C
    // if SIDE = 'L' and TRANS = 'N', or   Q'* C if SIDE = 'L' and
    // TRANS = 'T', or   C * Q if SIDE = 'R' and TRANS = 'N', or   C *
    // Q' if SIDE = 'R' and TRANS = 'T',
    void F77_NAME(dorm2r)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau,
			  double* c, const int& ldc,
			  double* work, int& info);

    // DORMBR - VECT = 'Q', DORMBR overwrites the general real M-by-N
    // matrix C with  SIDE = 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dormbr)(const char& vect, const char& side,
			  const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau,
			  double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DORMHR - overwrite the general real M-by-N matrix C with
    // SIDE = 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dormhr)(const char& side, const char& trans,
			  const int& m, const int& n,
			  const int& ilo, const int& ihi,
			  const double* a, const int& lda,
			  const double* tau,
			  double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DORML2 - overwrite the general real m by n matrix C with   Q *
    // C if SIDE = 'L' and TRANS = 'N', or   Q'* C if SIDE = 'L' and
    // TRANS = 'T', or   C * Q if SIDE = 'R' and TRANS = 'N', or   C *
    // Q' if SIDE = 'R' and TRANS = 'T',
    void F77_NAME(dorml2)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau,
			  double* c, const int& ldc, double* work, int& info);

    // DORMLQ - overwrite the general real M-by-N matrix C with
    // SIDE = 'L' SIDE = 'R' TRANS = 'N' 
    void F77_NAME(dormlq)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau, double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DORMQL - overwrite the general real M-by-N matrix C with
    // SIDE = 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dormql)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau, double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DORMQR - overwrite the general real M-by-N matrix C with   SIDE =
    // 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dormqr)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau, double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DORMR2 - overwrite the general real m by n matrix C with   Q *
    // C if SIDE = 'L' and TRANS = 'N', or   Q'* C if SIDE = 'L' and
    // TRANS = 'T', or   C * Q if SIDE = 'R' and TRANS = 'N', or   C *
    // Q' if SIDE = 'R' and TRANS = 'T',
    void F77_NAME(dormr2)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau, double* c, const int& ldc,
			  double* work, int& info);

    // DORMRQ - overwrite the general real M-by-N matrix C with
    // SIDE = 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dormrq)(const char& side, const char& trans,
			  const int& m, const int& n, const int& k,
			  const double* a, const int& lda,
			  const double* tau, double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DORMTR - overwrite the general real M-by-N matrix C with
    // SIDE = 'L' SIDE = 'R' TRANS = 'N'
    void F77_NAME(dormtr)(const char& side, const char& uplo,
			  const char& trans, const int& m, const int& n,
			  const double* a, const int& lda,
			  const double* tau, double* c, const int& ldc,
			  double* work, const int& lwork, int& info);

    // DPBCON - estimate the reciprocal of the condition number (in
    // the 1-norm); of a real symmetric positive definite band matrix
    // using the Cholesky factorization A = U**T*U or A = L*L**T
    // computed by DPBTRF
    void F77_NAME(dpbcon)(const char& uplo, const int& n, const int& kd,
			  const double* ab, const int& ldab,
			  const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DPBEQU - compute row and column scalings intended to
    // equilibrate a symmetric positive definite band matrix A and
    // reduce its condition number (with respect to the two-norm);
    void F77_NAME(dpbequ)(const char& uplo, const int& n, const int& kd,
			  const double* ab, const int& ldab,
			  double* s, double& scond, double& amax, int& info);

    // DPBRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is symmetric positive
    // definite and banded, and provides error bounds and backward
    // error estimates for the solution
    void F77_NAME(dpbrfs)(const char& uplo, const int& n,
			  const int& kd, const int& nrhs,
			  const double* ab, const int& ldab,
			  const double* afb, const int& ldafb,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DPBSTF - compute a split Cholesky factorization of a real
    // symmetric positive definite band matrix A
    void F77_NAME(dpbstf)(const char& uplo, const int& n, const int& kd,
			  double* ab, const int& ldab, int& info);

    // DPBSV - compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dpbsv)(const char& uplo, const int& n,
			 const int& kd, const int& nrhs,
			 double* ab, const int& ldab,
			 double* b, const int& ldb, int& info);

    // DPBSVX - use the Cholesky factorization A = U**T*U or A =
    // L*L**T to compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dpbsvx)(const int& fact, const char& uplo, const int& n,
			  const int& kd, const int& nrhs,
			  double* ab, const int& ldab,
			  double* afb, const int& ldafb,
			  char& equed, double* s,
			  double* b, const int& ldb,
			  double* x, const int& ldx, double& rcond,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DPBTF2 - compute the Cholesky factorization of a real
    // symmetric positive definite band matrix A
    void F77_NAME(dpbtf2)(const char& uplo, const int& n, const int& kd,
			  double* ab, const int& ldab, int& info);

    // DPBTRF - compute the Cholesky factorization of a real
    // symmetric positive definite band matrix A
    void F77_NAME(dpbtrf)(const char& uplo, const int& n, const int& kd,
			  double* ab, const int& ldab, int& info);

    // DPBTRS - solve a system of linear equations A*X = B with a
    // symmetric positive definite band matrix A using the Cholesky
    // factorization A = U**T*U or A = L*L**T computed by DPBTRF
    void F77_NAME(dpbtrs)(const char& uplo, const int& n,
			  const int& kd, const int& nrhs,
			  const double* ab, const int& ldab,
			  double* b, const int& ldb, int& info);

    // DPOCON - estimate the reciprocal of the condition number (in
    // the 1-norm); of a real symmetric positive definite matrix using
    // the Cholesky factorization A = U**T*U or A = L*L**T computed by
    // DPOTRF
    void F77_NAME(dpocon)(const char& uplo, const int& n,
			  const double* a, const int& lda,
			  const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DPOEQU - compute row and column scalings intended to
    // equilibrate a symmetric positive definite matrix A and reduce
    // its condition number (with respect to the two-norm);
    void F77_NAME(dpoequ)(const int& n, const double* a, const int& lda,
			  double* s, double& scond, double& amax, int& info);

    // DPORFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is symmetric positive
    // definite,
    void F77_NAME(dporfs)(const char& uplo, const int& n, const int& nrhs,
			  const double* a, const int& lda,
			  const double* af, const int& ldaf,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DPOSV - compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dposv)(const char& uplo, const int& n, const int& nrhs,
			 double* a, const int& lda,
			 double* b, const int& ldb, int& info);

    // DPOSVX - use the Cholesky factorization A = U**T*U or A =
    // L*L**T to compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dposvx)(const int& fact, const char& uplo,
			  const int& n, const int& nrhs,
			  double* a, const int& lda,
			  double* af, const int& ldaf, char& equed,
			  double* s, double* b, const int& ldb,
			  double* x, const int& ldx, double& rcond,
			  double* ferr, double* berr, double* work,
			  int* iwork, int& info);

    // DPOTF2 - compute the Cholesky factorization of a real
    // symmetric positive definite matrix A
    void F77_NAME(dpotf2)(const char& uplo, const int& n,
			  double* a, const int& lda, int& info);

    // DPOTRF - compute the Cholesky factorization of a real
    // symmetric positive definite matrix A
    void F77_NAME(dpotrf)(const char& uplo, const int& n,
			  double* a, const int& lda, int& info);

    // DPOTRI - compute the inverse of a real symmetric positive
    // definite matrix A using the Cholesky factorization A = U**T*U
    // or A = L*L**T computed by DPOTRF
    void F77_NAME(dpotri)(const char& uplo, const int& n,
			  double* a, const int& lda, int& info);

    // DPOTRS - solve a system of linear equations A*X = B with a
    // symmetric positive definite matrix A using the Cholesky
    // factorization A = U**T*U or A = L*L**T computed by DPOTRF
    void F77_NAME(dpotrs)(const char& uplo, const int& n,
			  const int& nrhs,
			  const double* a, const int& lda,
			  double* b, const int& ldb, int& info);

    // DPPCON - estimate the reciprocal of the condition number (in
    // the 1-norm); of a real symmetric positive definite packed
    // matrix using the Cholesky factorization A = U**T*U or A =
    // L*L**T computed by DPPTRF
    void F77_NAME(dppcon)(const char& uplo, const int& n,
			  const double* ap,
			  const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DPPEQU - compute row and column scalings intended to
    // equilibrate a symmetric positive definite matrix A in packed
    // storage and reduce its condition number (with respect to the
    // two-norm);
    void F77_NAME(dppequ)(const char& uplo, const int& n,
			  const double* ap, double* s, double& scond,
			  double& amax, int& info);

    // DPPRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is symmetric positive
    // definite and packed, and provides error bounds and backward
    // error estimates for the solution
    void F77_NAME(dpprfs)(const char& uplo, const int& n,
			  const int& nrhs,
			  const double* ap, const double* afp,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DPPSV - compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dppsv)(const char& uplo, const int& n,
			 const int& nrhs, const double* ap,
			 double* b, const int& ldb, int& info);

    // DPPSVX - use the Cholesky factorization A = U**T*U or A =
    // L*L**T to compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dppsvx)(const int& fact, const char& uplo,
			  const int& n, const int& nrhs, double* ap,
			  double* afp, char& equed, double* s,
			  double* b, const int& ldb,
			  double* x, const int& ldx,
			  double& rcond, double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DPPTRF - compute the Cholesky factorization of a real
    // symmetric positive definite matrix A stored in packed format
    void F77_NAME(dpptrf)(const char& uplo, const int& n,
			  double* ap, int& info);

    // DPPTRI - compute the inverse of a real symmetric positive
    // definite matrix A using the Cholesky factorization A = U**T*U
    // or A = L*L**T computed by DPPTRF 
    void F77_NAME(dpptri)(const char& uplo, const int& n,
			  double* ap, int& info);

    // DPPTRS - solve a system of linear equations A*X = B with a
    // symmetric positive definite matrix A in packed storage using
    // the Cholesky factorization A = U**T*U or A = L*L**T computed by
    // DPPTRF
    void F77_NAME(dpptrs)(const char& uplo, const int& n,
			  const int& nrhs, const double* ap,
			  double* b, const int& ldb, int& info);

    // DPTCON - compute the reciprocal of the condition number (in
    // the 1-norm); of a real symmetric positive definite tridiagonal
    // matrix using the factorization A = L*D*L**T or A = U**T*D*U
    // computed by DPTTRF
    void F77_NAME(dptcon)(const int& n,
			  const double* d, const double* e,
			  const double& anorm, double& rcond,
			  double* work, int& info);

    // DPTEQR - compute all eigenvalues and, optionally, eigenvectors
    // of a symmetric positive definite tridiagonal matrix by first
    // factoring the matrix using DPTTRF, and then calling DBDSQR to
    // compute the singular values of the bidiagonal factor
    void F77_NAME(dpteqr)(const char& compz, const int& n, double* d,
			  double* e, double* z, const int& ldz,
			  double* work, int& info);

    // DPTRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is symmetric positive
    // definite and tridiagonal, and provides error bounds and
    // backward error estimates for the solution
    void F77_NAME(dptrfs)(const int& n, const int& nrhs,
			  const double* d, const double* e,
			  const double* df, const double* ef,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int& info);

    // DPTSV - compute the solution to a real system of linear
    // equations A*X = B, where A is an N-by-N symmetric positive
    // definite tridiagonal matrix, and X and B are N-by-NRHS matrices
    void F77_NAME(dptsv)(const int& n, const int& nrhs, double* d,
			 double* e, double* b, const int& ldb, int& info);

    // DPTSVX - use the factorization A = L*D*L**T to compute the
    // solution to a real system of linear equations A*X = B, where A
    // is an N-by-N symmetric positive definite tridiagonal matrix and
    // X and B are N-by-NRHS matrices
    void F77_NAME(dptsvx)(const int& fact, const int& n,
			  const int& nrhs,
			  const double* d, const double* e,
			  double* df, double* ef,
			  const double* b, const int& ldb,
			  double* x, const int& ldx, double& rcond,
			  double* ferr, double* berr,
			  double* work, int& info);

    // DPTTRF - compute the factorization of a real symmetric
    // positive definite tridiagonal matrix A
    void F77_NAME(dpttrf)(const int& n, double* d, double* e, int& info);

    // DPTTRS - solve a system of linear equations A * X = B with a
    // symmetric positive definite tridiagonal matrix A using the
    // factorization A = L*D*L**T or A = U**T*D*U computed by DPTTRF
    void F77_NAME(dpttrs)(const int& n, const int& nrhs,
			  const double* d, const double* e,
			  double* b, const int& ldb, int& info); 

    // DRSCL - multiply an n-element real vector x by the real scalar
    // 1/a
    void F77_NAME(drscl)(const int& n, const double& da,
			 double* x, const int& incx);

    // DSBEV - compute all the eigenvalues and, optionally,
    // eigenvectors of a real symmetric band matrix A
    void F77_NAME(dsbev)(const char& jobz, const char& uplo,
			 const int& n, const int& kd,
			 double* ab, const int& ldab,
			 double* w, double* z, const int& ldz,
			 double* work, int& info);

    // DSBEVD - compute all the eigenvalues and, optionally,
    // eigenvectors of a real symmetric band matrix A
    void F77_NAME(dsbevd)(const char& jobz, const char& uplo,
			  const int& n, const int& kd,
			  double* ab, const int& ldab,
			  double* w, double* z, const int& ldz,
			  double* work, const int& lwork,
			  int* iwork, const int& liwork, int& info);

    // DSBEVX - compute selected eigenvalues and, optionally,
    // eigenvectors of a real symmetric band matrix A
    void F77_NAME(dsbevx)(const char& jobz, const char& range,
			  const char& uplo, const int& n, const int& kd,
			  double* ab, const int& ldab,
			  double* q, const int& ldq,
			  const double& vl, const double& vu,
			  const int& il, const int& iu,
			  const double& abstol,
			  int& m, double* w,
			  double* z, const int& ldz,
			  double* work, int* iwork,
			  int* ifail, int& info);

    // DSBGST - reduce a real symmetric-definite banded generalized
    // eigenproblem A*x = lambda*B*x to standard form C*y = lambda*y,
    void F77_NAME(dsbgst)(const char& vect, const char& uplo,
			  const int& n, const int& ka, const int& kb,
			  double* ab, const int& ldab,
			  double* bb, const int& ldbb,
			  double* x, const int& ldx,
			  double* work, int& info);

    // DSBGV - compute all the eigenvalues, and optionally, the
    // eigenvectors of a real generalized symmetric-definite banded
    // eigenproblem, of the form A*x=(lambda);*B*x
    void F77_NAME(dsbgv)(const char& jobz, const char& uplo,
			 const int& n, const int& ka, const int& kb,
			 double* ab, const int& ldab,
			 double* bb, const int& ldbb,
			 double* w, double* z, const int& ldz,
			 double* work, int& info);

    // DSBTRD - reduce a real symmetric band matrix A to symmetric
    // tridiagonal form T by an orthogonal similarity transformation
    void F77_NAME(dsbtrd)(const char& vect, const char& uplo,
			  const int& n, const int& kd,
			  double* ab, const int& ldab,
			  double* d, double* e,
			  double* q, const int& ldq,
			  double* work, int& info);

    // DSECND - return the user time for a process in seconds
    double F77_NAME(dsecnd)(void);

    // DSPCON - estimate the reciprocal of the condition number (in
    // the 1-norm); of a real symmetric packed matrix A using the
    // factorization A = U*D*U**T or A = L*D*L**T computed by DSPTRF
    void F77_NAME(dspcon)(const char& uplo, const int& n,
			  const double* ap, const int* ipiv,
			  const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DSPEV - compute all the eigenvalues and, optionally,
    // eigenvectors of a real symmetric matrix A in packed storage
    void F77_NAME(dspev)(const char& jobz, const char& uplo, const int& n,
			 double* ap, double* w, double* z, const int& ldz,
			 double* work, int& info);

    // DSPEVD - compute all the eigenvalues and, optionally,
    // eigenvectors of a real symmetric matrix A in packed storage
    void F77_NAME(dspevd)(const char& jobz, const char& uplo,
			  const int& n, double* ap, double* w,
			  double* z, const int& ldz,
			  double* work, const int& lwork,
			  int* iwork, const int& liwork, int& info);

    // DSPEVX - compute selected eigenvalues and, optionally,
    // eigenvectors of a real symmetric matrix A in packed storage
    void F77_NAME(dspevx)(const char& jobz, const char& range,
			  const char& uplo, const int& n, double* ap,
			  const double& vl, const double& vu,
			  const int& il, const int& iu,
			  const double* abstol,
			  int& m, double* w,
			  double* z, const int& ldz,
			  double* work, int* iwork,
			  int* ifail, int& info);

    // DSPGST - reduce a real symmetric-definite generalized
    // eigenproblem to standard form, using packed storage
    void F77_NAME(dspgst)(const int& itype, const char& uplo,
			  const int& n, double* ap, double* bp, int& info);

    // DSPGV - compute all the eigenvalues and, optionally, the
    // eigenvectors of a real generalized symmetric-definite
    // eigenproblem, of the form A*x=(lambda)*B*x, A*Bx=(lambda)*x,
    // or B*A*x=(lambda)*x
    void F77_NAME(dspgv)(const int& itype, const char& jobz,
			 const char& uplo, const int& n,
			 double* ap, double* bp, double* w,
			 double* z, const int& ldz,
			 double* work, int& info);

    // DSPRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is symmetric indefinite
    // and packed, and provides error bounds and backward error
    // estimates for the solution
    void F77_NAME(dsprfs)(const char& uplo, const int& n,
			  const int& nrhs, const double* ap,
			  const double* afp, const int* ipiv,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DSPSV - compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dspsv)(const char& uplo, const int& n,
			 const int& nrhs, double* ap, int* ipiv,
			 double* b, const int& ldb, int& info);

    // DSPSVX - use the diagonal pivoting factorization A = U*D*U**T
    // or A = L*D*L**T to compute the solution to a real system of
    // linear equations A * X = B, where A is an N-by-N symmetric
    // matrix stored in packed format and X and B are N-by-NRHS
    // matrices
    void F77_NAME(dspsvx)(const int& fact, const char& uplo,
			  const int& n, const int& nrhs,
			  const double* ap, double* afp, int* ipiv,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double& rcond, double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DSPTRD - reduce a real symmetric matrix A stored in packed
    // form to symmetric tridiagonal form T by an orthogonal
    // similarity transformation
    void F77_NAME(dsptrd)(const char& uplo, const int& n,
			  double* ap, double* d, double* e,
			  double* tau, int& info);

    // DSPTRF - compute the factorization of a real symmetric matrix
    // A stored in packed format using the Bunch-Kaufman diagonal
    // pivoting method
    void F77_NAME(dsptrf)(const char& uplo, const int& n,
			  double* ap, int* ipiv, int& info);

    // DSPTRI - compute the inverse of a real symmetric indefinite
    // matrix A in packed storage using the factorization A = U*D*U**T
    // or A = L*D*L**T computed by DSPTRF
    void F77_NAME(dsptri)(const char& uplo, const int& n,
			  double* ap, const int* ipiv,
			  double* work, int& info);

    // DSPTRS - solve a system of linear equations A*X = B with a
    // real symmetric matrix A stored in packed format using the
    // factorization A = U*D*U**T or A = L*D*L**T computed by DSPTRF
    void F77_NAME(dsptrs)(const char& uplo, const int& n,
			  const int& nrhs, const double* ap,
			  const int* ipiv, double* b, const int& ldb,
			  int& info);

    // DSTEBZ - compute the eigenvalues of a symmetric tridiagonal
    // matrix T
    void F77_NAME(dstebz)(const char& range, const char& order,
			  const int& n,
			  const double& vl, const double& vu,
			  const int& il, const int& iu,
			  const double &abstol,
			  const double* d, const double* e,
			  int& m, int& nsplit, double* w,
			  int* iblock, int* isplit,
			  double* work, int* iwork,
			  int& info);

    // DSTEDC - compute all eigenvalues and, optionally, eigenvectors
    // of a symmetric tridiagonal matrix using the divide and conquer
    // method
    void F77_NAME(dstedc)(const char& compz, const int& n,
			  double* d, double* e,
			  double* z, const int& ldz,
			  double* work, const int& lwork,
			  int* iwork, const int& liwork, int& info);

    // DSTEIN - compute the eigenvectors of a real symmetric
    // tridiagonal matrix T corresponding to specified eigenvalues,
    // using inverse iteration
    void F77_NAME(dstein)(const int& n, const double* d, const double* e,
			  const int& m, const double* w,
			  const int* iblock, const int* isplit,
			  double* z, const int& ldz,
			  double* work, int* iwork,
			  int* ifail, int& info);

    // DSTEQR - compute all eigenvalues and, optionally, eigenvectors
    // of a symmetric tridiagonal matrix using the implicit QL or QR
    // method
    void F77_NAME(dsteqr)(const char& compz, const int& n,
			  double* d, double* e,
			  double* z, const int& ldz,
			  double* work, int& info);

    // DSTERF - compute all eigenvalues of a symmetric tridiagonal
    // matrix using the Pal-Walker-Kahan variant of the QL or QR
    // algorithm
    void F77_NAME(dsterf)(const int& n, double* d, double* e, int& info);

    // DSTEV - compute all eigenvalues and, optionally, eigenvectors
    // of a real symmetric tridiagonal matrix A
    void F77_NAME(dstev)(const char& jobz, const int& n,
			 double* d, double* e,
			 double* z, const int& ldz,
			 double* work, int& info);

    // DSTEVD - compute all eigenvalues and, optionally, eigenvectors
    // of a real symmetric tridiagonal matrix
    void F77_NAME(dstevd)(const char& jobz, const int& n,
			  double* d, double* e,
			  double* z, const int& ldz,
			  double* work, const int& lwork,
			  int* iwork, const int& liwork, int& info);

    // DSTEVX - compute selected eigenvalues and, optionally,
    // eigenvectors of a real symmetric tridiagonal matrix A
    void F77_NAME(dstevx)(const char& jobz, const char& range,
			  const int& n, double* d, double* e,
			  const double& vl, const double& vu,
			  const int& il, const int& iu,
			  const double& abstol,
			  int& m, double* w,
			  double* z, const int& ldz,
			  double* work, int* iwork,
			  int* ifail, int& info);

    // DSYCON - estimate the reciprocal of the condition number (in
    // the 1-norm); of a real symmetric matrix A using the
    // factorization A = U*D*U**T or A = L*D*L**T computed by DSYTRF
    void F77_NAME(dsycon)(const char& uplo, const int& n,
			  const double* a, const int& lda,
			  const int* ipiv,
			  const double& anorm, double& rcond,
			  double* work, int* iwork, int& info);

    // DSYEV - compute all eigenvalues and, optionally, eigenvectors
    // of a real symmetric matrix A
    void F77_NAME(dsyev)(const char& jobz, const char& uplo,
			 const int& n, double* a, const int& lda,
			 double* w, double* work, const int& lwork,
			 int& info);

    // DSYEVD - compute all eigenvalues and, optionally, eigenvectors
    // of a real symmetric matrix A
    void F77_NAME(dsyevd)(const char& jobz, const char& uplo,
			  const int& n, double* a, const int& lda,
			  double* w, double* work, const int& lwork,
			  int* iwork, const int& liwork, int& info);

    // DSYEVX - compute selected eigenvalues and, optionally,
    // eigenvectors of a real symmetric matrix A
    void F77_NAME(dsyevx)(const char& jobz, const char& range,
			  const char& uplo, const int& n,
			  double* a, const int& lda,
			  const double& vl, const double& vu,
			  const int& il, const int& iu,
			  const double& abstol,
			  int& m, double* w,
			  double* z, const int& ldz,
			  double* work, const int& lwork, int* iwork,
			  int* ifail, int& info);

    // DSYGS2 - reduce a real symmetric-definite generalized
    // eigenproblem to standard form
    void F77_NAME(dsygs2)(const int& itype, const char& uplo,
			  const int& n, double* a, const int& lda,
			  const double* b, const int& ldb, int& info);

    // DSYGST - reduce a real symmetric-definite generalized
    // eigenproblem to standard form
    void F77_NAME(dsygst)(const int& itype, const char& uplo,
			  const int& n, double* a, const int& lda,
			  const double* b, const int& ldb, int& info);

    // DSYGV - compute all the eigenvalues, and optionally, the
    // eigenvectors of a real generalized symmetric-definite
    // eigenproblem, of the form A*x=(lambda);*B*x, A*Bx=(lambda);*x,
    // or B*A*x=(lambda);*x
    void F77_NAME(dsygv)(const int& itype, const char& jobz,
			 const char& uplo, const int& n,
			 double* a, const int& lda,
			 double* b, const int& ldb,
			 double* w, double* work, const int& lwork,
			 int& info);

    // DSYRFS - improve the computed solution to a system of linear
    // equations when the coefficient matrix is symmetric indefinite,
    // and provides error bounds and backward error estimates for the
    // solution
    void F77_NAME(dsyrfs)(const char& uplo, const int& n,
			  const int& nrhs,
			  const double* a, const int& lda,
			  const double* af, const int& ldaf,
			  const int* ipiv,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DSYSV - compute the solution to a real system of linear
    // equations  A * X = B,
    void F77_NAME(dsysv)(const char& uplo, const int& n,
			 const int& nrhs,
			 double* a, const int& lda, int* ipiv,
			 double* b, const int& ldb,
			 double* work, const int& lwork, int& info);

    // DSYSVX - use the diagonal pivoting factorization to compute
    // the solution to a real system of linear equations A * X = B,
    void F77_NAME(dsysvx)(const int& fact, const char& uplo,
			  const int& n, const int& nrhs,
			  const double* a, const int& lda,
			  double* af, const int& ldaf, int* ipiv,
			  const double* b, const int& ldb,
			  double* x, const int& ldx, double& rcond,
			  double* ferr, double* berr,
			  double* work, const int& lwork,
			  int* iwork, int& info);

    // DSYTD2 - reduce a real symmetric matrix A to symmetric
    // tridiagonal form T by an orthogonal similarity transformation
    void F77_NAME(dsytd2)(const char& uplo, const int& n,
			  double* a, const int& lda,
			  double* d, double* e, double* tau,
			  int& info);

    // DSYTF2 - compute the factorization of a real symmetric matrix
    // A using the Bunch-Kaufman diagonal pivoting method
    void F77_NAME(dsytf2)(const char& uplo, const int& n,
			  double* a, const int& lda,
			  int* ipiv, int& info);

    // DSYTRD - reduce a real symmetric matrix A to real symmetric
    // tridiagonal form T by an orthogonal similarity transformation
    void F77_NAME(dsytrd)(const char& uplo, const int& n,
			  double* a, const int& lda,
			  double* d, double* e, double* tau,
			  double* work, const int& lwork, int& info);

    // DSYTRF - compute the factorization of a real symmetric matrix
    // A using the Bunch-Kaufman diagonal pivoting method
    void F77_NAME(dsytrf)(const char& uplo, const int& n,
			  double* a, const int& lda, int* ipiv,
			  double* work, const int& lwork, int& info);

    // DSYTRI - compute the inverse of a real symmetric indefinite
    // matrix A using the factorization A = U*D*U**T or A = L*D*L**T
    // computed by DSYTRF
    void F77_NAME(dsytri)(const char& uplo, const int& n,
			  double* a, const int& lda, const int* ipiv,
			  double* work, int& info); 

    // DSYTRS - solve a system of linear equations A*X = B with a
    // real symmetric matrix A using the factorization A = U*D*U**T or
    // A = L*D*L**T computed by DSYTRF
    void F77_NAME(dsytrs)(const char& uplo, const int& n,
			  const int& nrhs,
			  const double* a, const int& lda,
			  const int* ipiv,
			  double* b, const int& ldb, int& info);

    // DTBCON - estimate the reciprocal of the condition number of a
    // triangular band matrix A, in either the 1-norm or the
    // infinity-norm
    void F77_NAME(dtbcon)(const char& norm, const char& uplo,
			  const char& diag, const int& n, const int& kd,
			  const double* ab, const int& ldab,
			  double& rcond, double* work,
			  int* iwork, int& info); 
    // DTBRFS - provide error bounds and backward error estimates for
    // the solution to a system of linear equations with a triangular
    // band coefficient matrix
    void F77_NAME(dtbrfs)(const char& uplo, const char& trans,
			  const char& diag, const int& n, const int& kd,
			  const int& nrhs,
			  const double* ab, const int& ldab,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);  
 
    // DTBTRS - solve a triangular system of the form   A * X = B or
    // A**T * X = B, 
    void F77_NAME(dtbtrs)(const char& uplo, const char& trans,
			  const char& diag, const int& n,
			  const int& kd, const int& nrhs,
			  const double* ab, const int& ldab,
			  double* b, const int& ldb, int& info); 

    // DTGEVC - compute some or all of the right and/or left
    // generalized eigenvectors of a pair of real upper triangular
    // matrices (A,B);
    void F77_NAME(dtgevc)(const char& side, const char& howmny,
			  const int* select, const int& n,
			  const double* a, const int& lda,
			  const double* b, const int& ldb,
			  double* vl, const int& ldvl,
			  double* vr, const int& ldvr,
			  const int& mm, int& m, double* work,
			  int& info);

    // DTGSJA - compute the generalized singular value decomposition
    // (GSVD); of two real upper triangular (or trapezoidal); matrices
    // A and B
    void F77_NAME(dtgsja)(const char& jobu, const char& jobv, const char& jobq,
			  const int& m, const int& p, const int& n,
			  const int& k, const int& l,
			  double* a, const int& lda,
			  double* b, const int& ldb,
			  const double& tola, const double& tolb,
			  double* alpha, double* beta,
			  double* u, const int& ldu,
			  double* v, const int& ldv,
			  double* q, const int& ldq,
			  double* work, int& ncycle, int& info);

    // DTPCON - estimate the reciprocal of the condition number of a
    // packed triangular matrix A, in either the 1-norm or the
    // infinity-norm
    void F77_NAME(dtpcon)(const char& norm, const char& uplo,
			  const char& diag, const int& n,
			  const double* ap, double& rcond,
			  double* work, int* iwork, int& info);

    // DTPRFS - provide error bounds and backward error estimates for
    // the solution to a system of linear equations with a triangular
    // packed coefficient matrix
    void F77_NAME(dtprfs)(const char& uplo, const char& trans,
			  const char& diag, const int& n,
			  const int& nrhs, const double* ap,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info);

    // DTPTRI - compute the inverse of a real upper or lower
    // triangular matrix A stored in packed format
    void F77_NAME(dtptri)(const char& uplo, const char& diag,
			  const int& n, double* ap, int& info);

    // DTPTRS - solve a triangular system of the form   A * X = B or
    // A**T * X = B,
    void F77_NAME(dtptrs)(const char& uplo, const char& trans,
			  const char& diag, const int& n,
			  const int& nrhs, const double* ap,
			  double* b, const int& ldb, int& info); 

    // DTRCON - estimate the reciprocal of the condition number of a
    // triangular matrix A, in either the 1-norm or the infinity-norm
    void F77_NAME(dtrcon)(const char& norm, const char& uplo,
			  const char& diag, const int& n,
			  const double* a, const int& lda,
			  double& rcond, double* work,
			  int* iwork, int& info);

    // DTREVC - compute some or all of the right and/or left
    // eigenvectors of a real upper quasi-triangular matrix T
    void F77_NAME(dtrevc)(const char& side, const char& howmny,
			  const int* select, const int& n,
			  const double* t, const int& ldt,
			  double* vl, const int& ldvl,
			  double* vr, const int& ldvr,
			  const int& mm, int& m, double* work,
			  int& info);

    // DTREXC - reorder the real Schur factorization of a real matrix
    // A = Q*T*Q**T, so that the diagonal block of T with row index
    // IFST is moved to row ILST
    void F77_NAME(dtrexc)(const char& compq, const int& n,
			  double* t, const int& ldt,
			  double* q, const int& ldq,
			  int& ifst, int& ILST,
			  double* work, int& info);

    // DTRRFS - provide error bounds and backward error estimates for
    // the solution to a system of linear equations with a triangular
    // coefficient matrix
    void F77_NAME(dtrrfs)(const char& uplo, const char& trans,
			  const char& diag, const int& n, const int& nrhs,
			  const double* a, const int& lda,
			  const double* b, const int& ldb,
			  double* x, const int& ldx,
			  double* ferr, double* berr,
			  double* work, int* iwork, int& info); 

    // DTRSEN - reorder the real Schur factorization of a real matrix
    // A = Q*T*Q**T, so that a selected cluster of eigenvalues appears
    // in the leading diagonal blocks of the upper quasi-triangular
    // matrix T,
    void F77_NAME(dtrsen)(const char& job, const char& compq,
			  const int* select, const int& n,
			  double* t, const int& ldt,
			  double* q, const int& ldq,
			  double* wr, double* wi,
			  int& m, double& s, double& sep,
			  double* work, const int& lwork,
			  int* iwork, const int& liwork, int& info);

    // DTRSNA - estimate reciprocal condition numbers for specified
    // eigenvalues and/or right eigenvectors of a real upper
    // quasi-triangular matrix T (or of any matrix Q*T*Q**T with Q
    // orthogonal);
    void F77_NAME(dtrsna)(const char& job, const char& howmny,
			  const int* select, const int& n,
			  const double* t, const int& ldt,
			  const double* vl, const int& ldvl,
			  const double* vr, const int& ldvr,
			  double* s, double* sep, const int& mm,
			  int& m, double* work, const int& lwork,
			  int* iwork, int& info);

    // DTRSYL - solve the real Sylvester matrix equation
    void F77_NAME(dtrsyl)(const char& trana, const char& tranb,
			  const int& isgn, const int& m, const int& n,
			  const double* a, const int& lda,
			  const double* b, const int& ldb,
			  double* c, const int& ldc,
			  double& scale, int& info);  

    // DTRTI2 - compute the inverse of a real upper or lower
    // triangular matrix
    void F77_NAME(dtrti2)(const char& uplo, const char& diag,
			  const int& n, double* a, const int& lda,
			  int& info); 

    // DTRTRI - compute the inverse of a real upper or lower
    // triangular matrix A
    void F77_NAME(dtrtri)(const char& uplo, const char& diag,
			  const int& n, double* a, const int& lda,
			  int& info); 

    // DTRTRS - solve a triangular system of the form   A * X = B or
    // A**T * X = B, 
    void F77_NAME(dtrtrs)(const char& uplo, const char& trans,
			  const char& diag, const int& n, const int& nrhs,
			  const double* a, const int& lda,
			  double* b, const int& ldb, int& info); 

    // DTZRQF - reduce the M-by-N ( M<=N ); real upper trapezoidal
    // matrix A to upper triangular form by means of orthogonal
    // transformations 
    void F77_NAME(dtzrqf)(const int& m, const int& n,
			  double* a, const int& lda,
			  double* tau, int& info);

    // DZSUM1 - take the sum of the absolute values of a complex
    // vector and returns a double precision result 
    //double F77_NAME(dzsum1)(const int& n, CX, const int& incx);

//orphans
    void F77_NAME(dtimmg)(const int& iflag, const int& m, const int& n,
			  double* A, const int& lda, const int& kl,
			  const int& ku); 
    double F77_NAME(dopla)(const char& subname, const int& m,
			   const int& n, const int& kl, const int& ku,
			   const int& nb); 
}