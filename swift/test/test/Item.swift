//
//  Item.swift
//  test
//
//  Created by Nathan Dohm on 1/16/22.
//

import SwiftUI

struct Item: Identifiable {
    var id = UUID()
    let url: URL
}

extension Item: Equatable {
    static func ==(lhs: Item, rhs: Item) -> Bool {
        return lhs.id == rhs.id && lhs.id == rhs.id
    }
}


