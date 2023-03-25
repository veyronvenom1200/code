//
//  CleanTrailsApp.swift
//  CleanTrails
//
//  Created by Nathan Dohm on 1/17/22.
//

import SwiftUI

@main
struct CleanTrailsApp: App {
    
    let persistenceController = PersistenceController.shared
    @Environment(\.scenePhase) var scenePhase


    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
        .onChange(of: scenePhase) { _ in
            persistenceController.save()
        }
    }
}
