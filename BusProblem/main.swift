//
//  main.swift
//  BusProblem
//
//  Created by ハイラル・ゼルダ on 2025.03.14.
//

//一小時內隨機發出6輛公交車，求等待時間的期望

import Foundation
import BigNumber

struct Couple:Hashable{
    var m:Int
    var n:Int
    
    init(m:Int,n:Int){
        self.m = m
        self.n = n
    }
    
}

var f = [Couple:BInt]()
var c = [Couple:BInt]()

func get_c(m:Int,n:Int) -> BInt{
    if let ans = c[Couple(m:m,n:n)] {
        return ans
    }
    else {
        if (m==n || n==0) {
            return 1
        }
        else{
            let ans = get_c(m: m-1, n: n-1) + get_c(m: m-1, n: n)
            c[Couple(m: m, n: n)]=ans
            return ans
        }
    }
}

func get_f(m:Int,n:Int) -> BInt{
    if m==1 {
        return BInt(n*n)
    }
    else if m==2{
        return BInt(n*(n-1)*(2*n-1)/3)
    }
    if let ans = f[Couple(m:m,n:n)] {
        return ans
    }
    else {
        var ans:BInt=0
        for i in 1...n-m+1 {
            ans+=i*i*get_c(m: n-1-i, n: m-2)+get_f(m: m-1, n: n-i)
        }
        f[Couple(m:m,n:n)] = ans
        return ans
    }
}

let u=BInt(10)**BInt(50)
var a=6
while true {
    print(a,u*get_f(m: 6, n: a)/(get_c(m: a-1, n:5)*a*a))
    a+=1000
}
