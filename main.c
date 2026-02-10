#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jll4n");
MODULE_DESCRIPTION("Random gen num");

static int __init random_init(void) {
    printk(KERN_INFO "Random module loaded\n");
    return 0;
}

static void __exit random_exit(void) {
    printk(KERN_INFO "Random module unloaded\n");
}

int random_function(int ts, int min, int max){
    int frac = 1/(ts);
    int num = frac*frac;
    int result = 0;
    if (num % 2 == 0){
        result = num/2;
    } else {
        result = num*3 + 1;
    }
    return result;
}

int random_gen_num(int min, int max){
    ktime_t timestamp = ktime_get();
    int ns = ktime_to_ns(timestamp);
    return ns;
}