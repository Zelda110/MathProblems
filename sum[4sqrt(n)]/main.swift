//
//  main.swift
//  sum[4sqrt(n)]
//
//  Created by ハイラル・ゼルダ on 2025/5/4.
//

import Foundation

var s = 0.0

for i in 1...2017{
    s += 1/(Double(floor(sqrt(sqrt(Double(i)))+0.5)))
}

print(s)
