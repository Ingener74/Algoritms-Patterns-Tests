#!/usr/bin/env python

import SwigTest as st

class Test(st.B, st.C, st.D):
    def __init__(self):
        st.B.__init__(self)
        st.D.__init__(self)
        st.C.__init__(self)

def main():
    
    test = Test()
    
    e = st.E()
    e.testE(test)
    
    f = st.F()
    f.testF(test)
    
    t = st.T()
    t.testT(test)
    
    pass

if __name__ == '__main__':
    main()