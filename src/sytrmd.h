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

#ifndef _LA_SYMM_TRIDIAG_MAT_DOUBLE_H_
#define _LA_SYMM_TRIDIAG_MAT_DOUBLE_H_

#include LA_VECTOR_DOUBLE_H

class LaSymmTridiagMatDouble
{   
        int size_;
        LaVectorDouble d_;          /* main diag */
        LaVectorDouble dl_;         /* lower diag */
        static double outofbounds_; /* return this address, when addresing 
                                        out of bounds */
        static int *info_;        // print matrix info only, not values
                                  //   originally 0, set to 1, and then
                                  //   reset to 0 after use.

    public:

        // constructors / destructor
    
        inline LaSymmTridiagMatDouble();
        inline LaSymmTridiagMatDouble(int N);
        inline LaSymmTridiagMatDouble(const LaSymmTridiagMatDouble &);
        inline ~LaSymmTridiagMatDouble();

        // operators and member functions

                double& operator()(int i, int j);
                double operator()(int i, int j) const;
                LaVectorDouble diag(int); /* 0 main, -1 lower, 1 upper */
                LaVectorDouble diag(int) const;
        inline LaSymmTridiagMatDouble& ref(LaSymmTridiagMatDouble&); 
        inline LaSymmTridiagMatDouble& copy(const LaSymmTridiagMatDouble&); 
        inline const LaSymmTridiagMatDouble& info() const {
            int *t = info_;
            *t = 1;
            return *this;};
        inline int size() const; 

        friend ostream& operator<<(ostream&,const LaSymmTridiagMatDouble&);


};

    // constructors

inline LaSymmTridiagMatDouble::LaSymmTridiagMatDouble(): 
        d_(), dl_()
{
    size_ = 0;
}

inline LaSymmTridiagMatDouble::LaSymmTridiagMatDouble(int N): 
        d_(N), dl_(N-1)
{
    size_ = N;
}
    
inline LaSymmTridiagMatDouble::LaSymmTridiagMatDouble(const LaSymmTridiagMatDouble& td): d_(td.d_), dl_(td.dl_)
{
    size_ = td.size_;
}

    // destructor

inline LaSymmTridiagMatDouble::~LaSymmTridiagMatDouble()
{
}


    // operators and member functions



inline LaSymmTridiagMatDouble& LaSymmTridiagMatDouble::ref(LaSymmTridiagMatDouble&T) 
{
    d_.ref(T.d_);
    dl_.ref(T.dl_); 
    size_ = T.size_;

    return *this;
}


inline LaSymmTridiagMatDouble& LaSymmTridiagMatDouble::copy(const LaSymmTridiagMatDouble&T) 
{
    d_.copy(T.d_);
    dl_.copy(T.dl_);    
    size_ = T.size_;

    return *this;
}

inline int LaSymmTridiagMatDouble::size() const
{
    return size_;
}



#endif 
// _LA_SYMM_TRIDIAG_MAT_DOUBLE_H_