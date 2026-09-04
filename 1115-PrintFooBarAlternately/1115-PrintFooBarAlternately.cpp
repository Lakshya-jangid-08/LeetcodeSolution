// Last updated: 9/4/2026, 9:25:16 PM
1class FooBar {
2private:
3    int n;
4    atomic<int> v{0};
5public:
6    FooBar(int n) {
7        this->n = n;
8    }
9
10    void foo(function<void()> printFoo) {
11        
12        for (int i = 0; i < n; i++) {
13            while(v&1) {}
14        	// printFoo() outputs "foo". Do not change or remove this line.
15        	printFoo();
16            v += 1;
17        }
18    }
19
20    void bar(function<void()> printBar) {
21        
22        for (int i = 0; i < n; i++) {
23            while(!(v&1)) {}
24        	// printBar() outputs "bar". Do not change or remove this line.
25        	printBar();
26            v += 1;
27        }
28    }
29};