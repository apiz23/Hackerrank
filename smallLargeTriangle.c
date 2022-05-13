#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n){
    
    double halfPeri,temp;
    /* Allocating memory for an array of size n. */
    int *area=malloc(n*sizeof(int)); 
    /* This is calculating the area of each triangle and storing it in the array area. */
    for(int i = 0; i < n; i++){
        halfPeri = (tr[i].a + tr[i].b + tr[i].c)/2.0;
        area[i] = halfPeri*(halfPeri-tr[i].a)*(halfPeri-tr[i].b)*(halfPeri-tr[i].c);
    }
    //Bubble sort sorting
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(area[i] > area[j]){

                //swap for area
                temp = area[i];
                area[i] = area[j];
                area[j] = temp;
                
                //swap for struct
                temp = tr[i].a; 
                tr[i].a = tr[j].a;
                tr[j].a = temp;
                
                temp = tr[i].b;
                tr[i].b = tr[j].b;
                tr[j].b = temp;
                
                temp = tr[i].c;
                tr[i].c = tr[j].c;
                tr[j].c = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}