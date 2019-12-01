#include <iostream>
#include <array>

template<std::size_t N>
int partition( std::array<int,N>& array , int left , int right , int pivot )
{
    while( left <= right ) {
        while(array[left] < pivot ) {
            left++;
        }
        while(array[right] > pivot ) {
            right--;
        }
        if(left <= right) {
            std::swap(array[left],array[right]);
            left++;
            right--;
        }
    }
    return left;
}

template<std::size_t N>
void quicksort( std::array<int,N>& array , int left , int right ) {
    if( left >= right) {
        return;
    }
    int pivot = array[(left + right) / 2  ];
    int index = partition(array,left,right,pivot);
    quicksort(array,left,index-1);
    quicksort(array,index,right);
}

template<std::size_t N>
void quicksort( std::array<int,N>& array ) {
    if ( array.empty() ) 
        return;
    }
    quicksort(array,0,array.size() - 1);
}


int main( void ) 
{
    std::array<int,5> array = {{ 12 , 5 , 99 , 9 , 5 }}; // double braces bc of std::initializer_list shenanighans

    quicksort( array );

    for( auto const& i : array ) {
        std::cout << i << "\n";
    }

    return 0;
}
