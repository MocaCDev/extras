#include <stdio.h>
#include <stdbool.h>

int build_arr(int length);

static bool two_d = true;
static bool print_ = true;

bool is_two_d(bool y);
bool print(bool p);

int main() {
    
    is_two_d(true);
    
    build_arr(2);
    
    return 0;
}

int build_arr(int length) {
    if(two_d) {
        int d_one;
        printf("Dimension array one: ");
        scanf("%d",&d_one);
        int d_two = length;
        int arr[d_one][length];
        
        for(int i = 0;i<d_one;i++) {
            for(int b = 0;b<length;b++){
                int get;
                printf("Number #%d -> ",b);
                scanf("%d",&get);
                arr[i][b] = get;
            }
        }
        
				if(print_) {
					int index_one;
					int index_two;

					printf("Dimension #1, Index #(starting from 0, to %d) -> ",d_one-1);
					scanf("%d",&index_one);

					printf("Dimension #2, Index #(starting from 0, to %d) -> ",d_two-1);
					scanf("%d",&index_two);

					if(index_one > d_one-1 || index_two > d_two-1) {
						printf("Default print: %d\n",arr[0][0]);
					} else {
        		printf("Number: %d\n",arr[index_one][index_two]);
					}
				}
    } else {
        int d_one = length;
        int arr[length];
        for(int i = 0; i < length; i++) {
            int num;
            printf("Number #%d -> ",i);
            scanf("%d",&num);
            arr[i] = num;
        }
        
				if(print_) {
					int index_;
					printf("Index #(starting from 0, to %d): ",length-1);
					scanf("%d",&index_);
					if(index_ > length-1) {
						printf("Default print: %d\n",arr[0]);
					} else {
        		printf("Number: %d\n",arr[index_]);
					}
				}
    }

		return 0;
}
bool is_two_d(bool y) {
    if(y) {
        two_d = true;
    } else {
        two_d = false;
    }

		return y;
}
bool print(bool p) {
	if(p) {
		print_ = true;
	} else {
		print_ = false;
	}

	return p;
}
