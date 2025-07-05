//
//  main.swift
//  average carddraw
//
//  Created by ハイラル・ゼルダ on 22/6/2025.
//

import Foundation

//疑lqe“多魚”摸牌量

var n = 0
var s = 0

while true{
    var m = 0
    while true{
        if Int.random(in: 1...13) <= 2{
            break
        }
        m += 1
    }
    s += 1
    n += m
    if s%1000 == 0 {
        print(Double(n)/Double(s))
    }
}
