#include "HamingBruteForce.h"

template<typename T>
HamingBruteForce<T>::HamingBruteForce(int n_size_reserve_, int n_dim_, int threshold)
        : n_size_reserve(n_size_reserve_), n_dim(n_dim_), index_ab(n_size_reserve, -1),
          distance_ab(n_size_reserve, threshold) {

}

template<typename T>
int HamingBruteForce<T>::hamming_distance(const T *a, const T *b, const int n) {
    int distance = 0;
    for (int i = 0; i < n; i++)
        distance += a[i] ^ b[i];
    return distance;
}

template<typename T>
void HamingBruteForce<T>::match(const T *a, int i_a, int n_size_a, const T *b, int i_b,
                                int n_size_b) {
    int d_ab = hamming_distance(a, b, n_dim);
    int is_closer = d_ab < distance_ab[i_a];
    index_ab[i_a] = is_closer ? i_b : index_ab[i_a];
    distance_ab[i_a] = is_closer ? d_ab : distance_ab[i_a];
}