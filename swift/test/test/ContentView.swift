//
//  ContentView.swift
//  test
//
//  Created by Nathan Dohm on 1/12/22.
//

import SwiftUI

struct ContentView: View {
    @State private var showingPhotoView = false
    @StateObject var dataModel = DataModel()
    
    var body: some View {
        Text("Hello, world!")
        Button("Press me, baby") {
            showingPhotoView.toggle()
        }
        .padding()
        .background(.blue)
        .cornerRadius(15)
        .foregroundColor(.white)
        .sheet(isPresented: $showingPhotoView) {
            PhotoView(isPresented: $showingPhotoView)
        }
    }
//        .backgroundColor(Color.black)
    
//    func buttonTapped() -> Int {
//        return buttonTap + 1
//    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
