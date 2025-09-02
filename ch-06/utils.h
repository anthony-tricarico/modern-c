/* Compute the GCD between two integer numbers */
int GCD(int m, int n) {
    int remainder;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;
}
