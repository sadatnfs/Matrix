// -*- c++ -*-
//              LAPACK++ 1.1 Linear Algebra Package 1.1
//               University of Tennessee, Knoxvilee, TN.
//            Oak Ridge National Laboratory, Oak Ridge, TN.
//        Authors: J. J. Dongarra, E. Greaser, R. Pozo, D. Walker
//                 (C) 1992-1996 All Rights Reserved
//
//                             NOTICE
//
// Permission to use, copy, modify, and distribute this software and
// its documentation for any purpose and without fee is hereby granted
// provided that the above copyright notice appear in all copies and
// that both the copyright notice and this permission notice appear in
// supporting documentation.
//
// Neither the Institutions (University of Tennessee, and Oak Ridge National
// Laboratory) nor the Authors make any representations about the suitability 
// of this software for any purpose.  This software is provided ``as is'' 
// without express or implied warranty.
//
// LAPACK++ was funded in part by the U.S. Department of Energy, the
// National Science Foundation and the State of Tennessee.
//
// Modifications Copyright (C) 2000-2000 the R Development Core Team

#ifndef _LA_SPD_FACT_DOUBLE_H_
#define _LA_SPD_FACT_DOUBLE_H_

#include LA_SPD_MAT_DOUBLE_H

#include "lapack.h"

class LaSpdFactDouble
{
 private:
    int size_;
    int gdim_;
    LaSpdMatDouble S_;
    
 public:
    LaSpdFactDouble();
    LaSpdFactDouble(int,int);
    LaSpdFactDouble(const LaSpdFactDouble&);
    ~LaSpdFactDouble();
    
    LaSpdFactDouble& ref(LaSpdFactDouble&);
    LaSpdFactDouble& ref(LaSpdMatDouble&);
    LaSpdFactDouble& copy(const LaSpdFactDouble&);
    LaSpdFactDouble& copy(const LaSpdMatDouble&);
    
    LaSpdMatDouble& S() { return S_; }
    int size() { return size_; }
    int gdim() { return gdim_; }
};


inline LaSpdFactDouble::LaSpdFactDouble(): S_(), size_(0), gdim_(0)
{}

inline LaSpdFactDouble::LaSpdFactDouble(int m,int n):S_(m,n), 
    size_(n), gdim_(m)
{}

inline LaSpdFactDouble::LaSpdFactDouble(const LaSpdFactDouble &X)
{
    size_ = X.size_;
    gdim_ = X.gdim_;
    S_.copy(X.S_);
}

inline LaSpdFactDouble::~LaSpdFactDouble()
{}

inline LaSpdFactDouble& LaSpdFactDouble::ref(LaSpdFactDouble &X)
{
    size_ = X.size_;
    gdim_ = X.gdim_;
    S_.ref(X.S_);

    return *this;
}

inline LaSpdFactDouble& LaSpdFactDouble::ref(LaSpdMatDouble &X)
{
    size_ = X.size(1);
    gdim_ = X.gdim(0);
    S_.ref(X);

    return *this;
}
    
inline LaSpdFactDouble& LaSpdFactDouble::copy(const LaSpdFactDouble &X)
{
    size_ = X.size_;
    gdim_ = X.gdim_;
    S_.copy(X.S_);

    return *this;
}

inline LaSpdFactDouble& LaSpdFactDouble::copy(const LaSpdMatDouble &X)
{
    size_ = X.size(1);
    gdim_ = X.gdim(0);
    S_.copy(X);

    return *this;
}

inline void LaSpdMatFactorize(LaSpdMatDouble &A, LaSpdFactDouble &AF)
{
    char uplo = 'L';
    integer N = A.size(1), lda = A.gdim(0), info = 0;
    AF.copy(A);

    F77_CALL(dpotrf)(&uplo, &N, &(AF.S()(0,0)), &lda, &info);
}


inline void LaLinearSolve(LaSpdFactDouble &AF, LaGenMatDouble &X,
			  LaGenMatDouble &B)
{
    char uplo = 'L';
    integer N = AF.size(), nrhs = X.size(1), lda = AF.gdim(), 
	ldb = B.size(0), info = 0;

    X.inject(B);
    F77_CALL(dpotrs)(&uplo, &N, &nrhs, &(AF.S()(0,0)), &lda, &X(0,0),
                    &ldb, &info);
}

#endif 
// _LA_SPD_FACT_DOUBLE_H_