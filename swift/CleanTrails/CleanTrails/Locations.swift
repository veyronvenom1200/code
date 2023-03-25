//
//  Locations.swift
//  CleanTrails
//
//  Created by Nathan Dohm on 1/18/22.
//

//
//  Location.swift
//  CleanTrails
//
//  Created by Nathan Dohm on 1/18/22.
//

import SwiftUI
import MapKit
import CoreLocation
import CoreLocationUI

//Hacking with swift
//wwdcbysundell.com

class LocationManager: NSObject, ObservableObject, CLLocationManagerDelegate {
    let manager = CLLocationManager()
    
    static let defaultDistance: CLLocationDistance = 50

    @Published var location = MKCoordinateRegion(
        center: CLLocationCoordinate2D(latitude: 42.0422448, longitude: -102.0079053),
        latitudinalMeters: LocationManager.defaultDistance,
        longitudinalMeters: LocationManager.defaultDistance
    )

    override init() {
        super.init()
        manager.delegate = self
    }

    func requestLocation() {
        manager.requestLocation()
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.first else { return }
            
        DispatchQueue.main.async {
            self.location = MKCoordinateRegion(
                center: location.coordinate,
                latitudinalMeters: Self.defaultDistance,
                longitudinalMeters: Self.defaultDistance
            )
        }
    }
    
    func locationManager(
        _ manager: CLLocationManager,
        didFailWithError error: Error
    ) {
        print("failed to get location")
    }
}

struct Coordinates {
    var id: UUID
    var latitude: String
    var longitude: String
}
