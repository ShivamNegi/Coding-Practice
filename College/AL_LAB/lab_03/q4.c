#include<stdio.h>
#include<limits.h>

int step_count = 0;
int ipow(int n){
	return 1 << n;
}
int main()
{
    int sum;
    int len, i;
    printf("Enter the number of elements\n");
    scanf("%d", &len);
	
    
    int set[len];
    printf("Enter the array:\n");

    
    for(i = 0; i < len; i++)
        scanf("%d", &set[i]);

    unsigned int pow_len = ipow(len);
    int arr[pow_len][len + 1];
    int counter, j;

    for(i = 0; i < pow_len; i++) 
    {
        for(j = 0; j < len; j++) 
        {
		arr[i][j] = INT_MIN;
	}
   }
 
    for(counter = 0; counter < pow_len; counter++)
    {
        sum = 0;
        for(j = 0; j < len; j++)
        {
            step_count++;
            if(counter & (1<<j)) {
		      sum += set[j];
		      arr[counter][j] = set[j];
	       }	    
       }
       arr[counter][len] = sum;
    }

    for(i = 0; i < pow_len; i++) {
	   for(j = i + 1; j < pow_len; j++) {
		if(arr[i][len] == arr[j][len]) {
			int is_disjoint = 1;
			for(counter = 0; counter < len; counter++) {
				if((arr[i][counter] == arr[j][counter]) && arr[i][counter] != INT_MIN && arr[j][counter] != INT_MIN) {
					is_disjoint = 0;
					break;
				}
				step_count++;
			}

			if(is_disjoint == 1) {
				printf("Found a pair for sum = %d:\n", arr[i][len]);
				printf("1st subset:\n");
				for(counter = 0; counter < len; counter++) {
					if(arr[i][counter] != INT_MIN)
						printf("%d ", arr[i][counter]);
				}
				printf("\n2nd subset:\n");
				for(counter = 0; counter < len; counter++) {
					if(arr[j][counter] != INT_MIN)
						printf("%d ", arr[j][counter]);
				}
				printf("\n");
			}
			
		}
	   }
    }

	printf("Step Count: %d\n", step_count);
  
    return 0;
}
