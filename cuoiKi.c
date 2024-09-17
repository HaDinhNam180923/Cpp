#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
   int a, b, n, c = 0, d = 0, e = 0, max;
   char name[7];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %s %d", &a, name, &b);
        if (strcmp(name, "Sind") == 0) c++;
        if (strcmp(name, "Vang") == 0) d++;
        if (strcmp(name, "Jersey") == 0) e++;
    }
   if (c < d) max = d; else max = c;
   if (max < e) max = e ;
    printf("%d", max);
    return 0;
}
