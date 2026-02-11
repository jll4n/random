#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jll4n");
MODULE_DESCRIPTION("Random gen num v1.0.1");

#define pi 3.1415926535

static int __init random_init(void) {
    printk(KERN_INFO "Random module loaded\n");
    return 0;
}

static void __exit random_exit(void) {
    printk(KERN_INFO "Random module unloaded\n");
}

int cos(int timestamp){
    while (timestamp > pi)  timestamp -= 2 * pi;
    double term = 1.0; 
    double sum = term;   
    int n;

    for (n = 1; n <= 10; n++) {
        term *= (-1.0) * x * x / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}

int random_function(int ts, int min, int max){
    if(min <= 0 || min == NULL){
        min = 0;
    }
    if(max <= 0 || max == NULL){
        max = 1;
    }
    ts = ts && 0b00000000000000000000000000000000111111111111111111111111; //verif masque
    int frac = cos(ts);
    int num = 0;
    int result = 0;
    if(ts%2==0 && frac<0){
        num = frac*frac;
    else
        num = frac;
    }
    if (num % 2 == 0){
        result = num/2;
    } else {
        result = num*(9/10);
    }
    return result;
}

int random_gen_num(int min, int max){
    ktime_t timestamp = ktime_get();
    int ns = ktime_to_ns(timestamp); //verif si bien timestamp ms et pas timestamp s 
    return ns;
}