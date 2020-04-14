import sys

t=int(input())
mod=998244353
while t!=0:
    s=input()
    stack=[]
    s1=""
    possiblility=0
    for i in range(len(s)):
        if s[i]=='#':
            s1+='#'
            possiblility+=1
        elif s[i]==')':
            while(stack[len(stack)-1]!='('):
                
                s1+=stack.pop()
                # stack.pop()
            stack.pop()
        else:
            stack.append(s[i])
    stack1=[]
    stack2=[]
    stack3=[]
    stack4=[]
    total=1
    a=0
    b=0
    d=0
    c=0
    # print(s1)
    for i in range(possiblility):
        total=(total*4)%mod
    # print(total)
    for i in range(len(s1)):
        if s1[i]=='#':
            stack1.append(1)
            stack2.append(1)
            stack3.append(1)
            stack4.append(1)
        else:

            p1=stack1.pop()
            p2=stack1.pop()
        
            q1=stack2.pop()
            # stack1.pop()
            q2=stack2.pop()
            # stack1.pop()
            r1=stack3.pop()
            # stack1.pop()
            r2=stack3.pop()
            # stack1.pop()
            z1=stack4.pop()
            # stack1.pop()
            z2=stack4.pop()
            # stack1.pop()
            # print(p1,p2,q1,q2,r1,r2,z1,z2)
            if s1[i]=='^':
    
                a=((p1%mod)*(p2%mod))%mod
                a=(a%mod+((q1%mod)*(q2%mod))%mod)%mod
                a=(a%mod+((r1%mod)*(r2%mod))%mod)%mod
                a=(a%mod+((z1%mod)*(z2%mod))%mod)%mod


                b=((p1%mod)*(q2%mod))%mod
                # print("b",b)
                b=((b%mod)+((q1%mod)*(p2%mod))%mod)%mod
                # print("b",b)
                b=(b%mod+((r1%mod)*(z2%mod)%mod))%mod
                # print("b",b/)
                b= ( b%mod+((z1%mod)*(r2%mod)) %mod )%mod
                # print("b",b)

                c=(p1%mod*r2%mod)%mod
                c=(c%mod+(q1%mod*z2%mod)%mod)%mod
                c=(c%mod+(r1%mod*p2%mod)%mod)%mod
                c=(c%mod+(z1%mod*q2%mod)%mod)%mod

                d=((p1%mod)*(z2%mod))%mod
                d=((d%mod)+(((q1%mod)*(r2%mod))%mod))%mod
                d=((d%mod)+(((r1%mod)*(q2%mod))%mod))%mod
                d=((d%mod)+(((z1%mod)*(p2%mod))%mod))%mod
                # print(a,b,c,d)

            

            elif(s1[i]=='|'):

                a=((p1%mod)*(p2%mod))%mod

                b=((p1%mod)*(q2%mod))%mod
                b=((b%mod)+(((q1%mod)*(p2%mod))%mod))%mod
                b=((b%mod)+(((q1%mod)*(q2%mod))%mod))%mod
                b=((b%mod)+(((q1%mod)*(r2%mod))%mod))%mod
                b=((b%mod)+(((q1%mod)*(z2%mod))%mod))%mod
                b=((b%mod)+(((r1%mod)*(q2%mod))%mod))%mod
                b=((b%mod)+(((r1%mod)*(z2%mod))%mod))%mod
                b=((b%mod)+(((z1%mod)*(q2%mod))%mod))%mod
                b=((b%mod)+(((z1%mod)*(r2%mod))%mod))%mod

                c=((p1%mod)*(r2%mod))%mod
                c=((c%mod)+(((r1%mod)*(p2%mod))%mod))%mod
                c=((c%mod)+(((r1%mod)*(r2%mod))%mod))%mod

                d=((p1%mod)*(z2%mod))%mod
                d=((d%mod)+(((z1%mod)*(p2%mod))%mod))%mod
                d=((d%mod)+(((z1%mod)*(z2%mod))%mod))%mod
                # print(a,b,c,d)


            else:


                a=((p1%mod)*(p2%mod))%mod
                a=((a%mod)+(((p1%mod)*(q2%mod))%mod))%mod
                a=((a%mod)+(((p1%mod)*(r2%mod))%mod))%mod
                a=((a%mod)+(((p1%mod)*(z2%mod))%mod))%mod
                a=((a%mod)+(((q1%mod)*(p2%mod))%mod))%mod
                a=((a%mod)+(((r1%mod)*(p2%mod))%mod))%mod
                a=((a%mod)+(((r1%mod)*(z2%mod))%mod))%mod
                a=((a%mod)+(((z1%mod)*(p2%mod))%mod))%mod
                a=((a%mod)+(((z1%mod)*(r2%mod))%mod))%mod

                b=((q1%mod)*(q2%mod))%mod

                c=((q1%mod)*(r2%mod))%mod
                c=((c%mod)+(((r1%mod)*(q2%mod))%mod))%mod
                c=((c%mod)+(((r1%mod)*(r2%mod))%mod))%mod

                d=((q1%mod)*(z2%mod))%mod
                d=((d%mod)+(((z1%mod)*(q2%mod))%mod))%mod
                d=((d%mod)+(((z1%mod)*(z2%mod))%mod))%mod
                # print(a,b,c,d)

            stack1.append(a)
            stack2.append(b)
            stack3.append(c)
            stack4.append(d)
            

    k1=stack1.pop()
    k2=stack2.pop()
    k3=stack3.pop()
    k4=stack4.pop()

    inverse=pow(total,mod-2,mod)

    zero=(k1*inverse)%mod
    one=(k2*inverse)%mod
    smalla=(k3*inverse)%mod
    A=(k4*inverse)%mod

    print(zero,one,smalla,A)

    t-=1






