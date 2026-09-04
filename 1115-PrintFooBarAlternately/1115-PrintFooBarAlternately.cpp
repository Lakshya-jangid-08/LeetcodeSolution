// Last updated: 9/4/2026, 9:33:51 PM
1class FooBar {
2private:
3    int n;
4    mutex fooLock, barLock;
5public:
6    FooBar(int n) {
7        this->n = n;
8        barLock.lock();            
9    }
10
11    void foo(function<void()> printFoo) {
12        
13        for (int i = 0; i < n; i++) {
14            fooLock.lock();            
15        	printFoo();
16            barLock.unlock();            
17        }
18    }
19
20    void bar(function<void()> printBar) {
21        
22        for (int i = 0; i < n; i++) {
23            barLock.lock();            
24        	printBar();
25            fooLock.unlock();            
26        }
27    }
28};