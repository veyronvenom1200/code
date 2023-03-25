//
//  SettingsView.swift
//  CleanTrails
//
//  Created by Nathan Dohm on 1/18/22.
//

import SwiftUI

struct SettingsView: View {
    @State private var appearanceToggle = true
    @Environment(\.colorScheme) var colorScheme
    
    var body: some View {
        Form {
            VStack {
                Toggle("Is Dark Mode Enabled", isOn: $appearanceToggle)
                Text(colorScheme == .dark ? "In dark mode" : "In light mode")
                    .padding()
                Text("Hello World")
                    .padding()
                Text("Hello World")
                    .padding()
                Text("Hello World")
                    .padding()
                Text("Hello World")
                    .padding()
            }
            
        }
    }
}

struct SettingsView_Previews: PreviewProvider {
    static var previews: some View {
        SettingsView()
    }
}
