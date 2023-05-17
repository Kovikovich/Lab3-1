#include "stack.h"

int main() {
    Stack st;
    st.push(6);
    st.push(60);
    st.push(40);
    st.show(); 
    st.multiPop(2);
    st.show(); 
    Stack st2(st);
    st2.show(); 
    Stack st3;
    st3 = st2;
    st3.show(); 
    return 0;
}