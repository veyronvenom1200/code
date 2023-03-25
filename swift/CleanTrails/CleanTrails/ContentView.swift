//
//  ContentView.swift
//  CleanTrails
//
//  Created by Nathan Dohm on 1/17/22.
//

import SwiftUI
import MapKit
import CoreLocation
import CoreLocationUI

//Hacking with swift
//wwdcbysundell.com

struct ContentView: View {
    @StateObject var locationManager = LocationManager()
    @State private var cleanButton = false
    @State private var isShowingDetailView = false

    var body: some View {
        NavigationView {
            GeometryReader { geo in
                ScrollView {
                    Map(coordinateRegion: $locationManager.location)
//                        .ignoresSafeArea(edges: .top)
                        .frame(height: geo.size.height * 0.6)
                    
                    LocationButton {
                        locationManager.requestLocation()
                        cleanButton = true
                    }
                    .alert("Thanks for keeping the trails clean!", isPresented: $cleanButton) {
                    Button("OK", role: .cancel) { }
                    }
                    .background(Color.blue)
                    .cornerRadius(15)
                    .foregroundColor(Color.white)
                    .padding()
//                    Button("Save") {
//                        PersistenceController.save()
//                    }
                    NavigationLink(destination: SavedLocationView()) {
                        Text("Saved Locations")
                    }
                    .background(Color.blue)
                    .cornerRadius(15)
                    .foregroundColor(Color.white)
                    .padding()
                }
//                .environment(\.verticalSizeClass, .compact)
//                .navigationTitle("CleanTrails")
                .navigationBarTitleDisplayMode(.inline)
                .toolbar {
                    ToolbarItem(placement: .navigationBarLeading) {
                        Button("Settings") {
                            SettingsView()
                        }
                    }
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
