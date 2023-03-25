//
//  ContentView.swift
//  Landmarks
//
//  Created by Nathan Dohm on 1/10/22.
//

import SwiftUI
import MapKit

struct ContentView: View {
    var body: some View {
        LandmarkList()
    }
}

struct test {
    var testRegion = MKCoordinateRegion(
        center: CLLocationCoordinate2D(latitude: 34.011_286, longitude: -116.166_868),
        span: MKCoordinateSpan(latitudeDelta: 0.2, longitudeDelta: 0.2))
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
