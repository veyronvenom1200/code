//
//  SavedLocationView.swift
//  CleanTrails
//
//  Created by Nathan Dohm on 1/18/22.
//

import SwiftUI

struct SavedLocationView: View {
    @FetchRequest(
        entity: SavedLocation.entity(),
        sortDescriptors: []
    ) var coordinates: FetchedResults<SavedLocation>
    
    var body: some View {
        List(coordinates) { language in
            Text(language.latitude ?? "Unknown")
                .foregroundColor(.white)
        }
        .listRowBackground(Color.white)

        Text("Hello")
    }
}

struct SavedLocationView_Previews: PreviewProvider {
    static var previews: some View {
        SavedLocationView()
    }
}
