//
//  PhotoView.swift
//  test
//
//  Created by Nathan Dohm on 1/15/22.
//

import SwiftUI

struct PhotoView: View {
    @Binding var isPresented: Bool
    
    var body: some View {
        VStack {
            Button("Dismiss") {
                isPresented = false
            }
            .padding()
            .background(.blue)
            .cornerRadius(15)
            .foregroundColor(.white)
            }
        .padding()
        ScrollView(.horizontal) {
            HStack(spacing: 10) {
                Image("tifa")
                    .resizable()
                    .scaledToFit()
                Image("IMG1")
                    .resizable()
                    .scaledToFit()
                Image("IMG2")
                    .resizable()
                    .scaledToFit()
                Image("IMG3")
                    .resizable()
                    .scaledToFit()
                Image("gwen")
                    .resizable()
                    .scaledToFit()
//                ForEach(0..<10) { image in
//                   Image("\(image)")
//                }
            }
        }
    }
}

//struct PhotoView_Previews: PreviewProvider {
//    static var previews: some View {
////        PhotoView(isPresented: false)
//    }
//}
