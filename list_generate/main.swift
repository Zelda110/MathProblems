//
//  main.swift
//  list_generate
//
//  Created by ハイラル・ゼルダ on 2025/5/5.
//

import Foundation

//生成数列

var n:[Double] = [0,1,2]

func get_an(a:Int) -> Double{
    return (n[a-1]*n[a-1]+1)/(n[a-2]+1/n[a-2])
}

for a in 3...10{
    let an = get_an(a: a)
    n.append(an)
    print(a,an)
}
