//
//  main.swift
//  NumberChoosingProblem
//
//  Created by ハイラル・ゼルダ on 2025/4/26.
//

//從0-9這10個數字中任取3個數字組成一個沒有重複的三位數，求這個數不能被3整除的概率

import Foundation

var nums = [0,1,2,3,4,5,6,7,8,9]
var dividable = 0
var all = 0

while true{
    for _ in 0...1000000 {
        all += 1
        nums.shuffle()
        if (nums[0]+nums[1]+nums[2])%3 == 0 {
            dividable += 1
        }
    }
    print(1-Float(dividable)/Float(all))
}

//ans = 13/20
