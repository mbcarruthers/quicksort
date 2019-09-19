#include <iostream>
#include <array>

template<std::size_t N>
void quicksort( std::array<int,N>& array , int left , int right ) {
    if( left >= right) {
        std::cout << "left >= right\n";
        return;
    }
    int pivot = array[(left + right) / 2  ];
    int index = partition(array,left,right,pivot);
    quicksort(array,left,index-1);
    quicksort(array,index,right);
}

template<std::size_t N>
void quicksort( std::array<int,N>& array ) {
    quicksort(array,0,array.size() - 1);
}


int main( void ) 
{
    std::array<int,5> array = {{ 12 , 5 , 99 , 9 , 5 }};

    quicksort( array );

    return 0;
}
