1. Integer limits you should memorize

    0 to 10^9 or 2^30 fits in int
    above that you need long long
    Type	     Range binary
    int	         -2^31 to 2^31 - 1
    unsigned int 0 to 2^32 - 1
    long long    -2^63 to 2^63 - 1

2. Integer overflow traps

    Trap 1: Multiplication happens before assignment.
        int a = 100000; ie 10^5
        long long b = a * a;       
        // causes overflow because a*a is integer multiplication and ans is converted to long long
        // but 10^5*10^5 = 10^10 does not fit in int 
        long long c = 1LL * a * a;
        // so first typecast the first a to long long, then multiply so that it is a long long multiplication

    