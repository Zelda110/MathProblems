//
//  main.swift
//  list_generate
//
//  Created by ハイラル・ゼルダ on 2025/5/5.
//

import Foundation

//生成數列

var n:[Double] = [sqrt(2)/2]

func getAn(_ i:Int) -> Double{
    return sqrt(2)*sqrt(1-sqrt(1-pow(n[i-1], 2)))/2
}

for a in 1...100{
    let an = getAn(a)
    n.append(an)
    print(a,an*pow(2, Double(a+2)))
}
