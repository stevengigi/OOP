#ifndef COOKIE_H
#define COOKIE_H

    double max_dv(int n, int* array) {
        if(n < 0){
            return -1;
        }
        // Total the dv on every odd position.
        int to = 0;
        // Total the dv on every even position
        int te = 0;

        for(int i = 0; i < n; i++){
            int dv = array[i];
            if(dv < 0 || dv > 100){
                return -1;
            }
            to+=(i%2)?0:dv;
            te+=(i%2)?dv:0;
        }
        // Return maximum between to and te.
        return to >= te ? to : te;
    }

#endif

