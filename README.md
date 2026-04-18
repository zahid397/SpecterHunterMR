<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,11,20&height=200&section=header&text=SpecterHunterMR&fontSize=52&fontColor=ffffff&animation=fadeIn&fontAlignY=38&desc=Asymmetrical%20Mixed%20Reality%20Multiplayer%20Game&descAlignY=58&descSize=18" width="100%"/>

<br/>

[![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-5-black?style=for-the-badge&logo=unrealengine&logoColor=white&labelColor=0D0D0D)](https://www.unrealengine.com/)
[![C++](https://img.shields.io/badge/C++-20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Meta XR](https://img.shields.io/badge/Meta%20XR-Plugin-0064E0?style=for-the-badge&logo=meta&logoColor=white)](https://developer.oculus.com/)
[![Status](https://img.shields.io/badge/Status-Prototype-F59E0B?style=for-the-badge&logo=flask&logoColor=white)](https://github.com/zahid397/SpecterHunterMR)

<br/>

> **👻 Hunt the invisible. 🥽 Feel the real. ⚡ Survive together.**
>
> A prototype asymmetrical mixed reality game where hunters and specters
> clash in a shared physical-digital world — powered by Unreal Engine 5.

<br/>

[🎮 View Demo](#-demo) · [🧩 Architecture](#-architecture) · [🚀 Getting Started](#-getting-started) · [👨‍💻 Author](#-author)

</div>

---

## 📸 Screenshots

<div align="center">

| 🎮 Gameplay View | 👻 Ghost Mode | 📡 Scanner HUD |
|:---:|:---:|:---:|
| *(MR Passthrough)* | *(Specter POV)* | *(Detection UI)* |
| ![gameplay](https://placehold.co/300x180/0D0D0D/6366F1?text=Gameplay+View&font=roboto) | ![ghost](https://placehold.co/300x180/0D0D0D/A855F7?text=Ghost+Mode&font=roboto) | ![scanner](https://placehold.co/300x180/0D0D0D/10B981?text=Scanner+HUD&font=roboto) |

</div>

---

## 🧠 What Is SpecterHunterMR?

```
┌─────────────────────────────────────────────────────────────────────┐
│                                                                     │
│   👁  Hunters wear Meta Quest headsets and see the real world      │
│       blended with digital ghost entities.                          │
│                                                                     │
│   👻  The Specter moves through the physical space, invisible      │
│       to the naked eye — only scanners can reveal them.             │
│                                                                     │
│   📡  Hunters use the Scanner System to detect, track and          │
│       trap specters before time runs out.                           │
│                                                                     │
│   ⚡  All logic runs in real-time via Unreal Engine 5 C++          │
│       with actor-based architecture for clean modularity.           │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

---

## ✨ Features

<table>
<tr>
<td width="50%">

### 🎯 Gameplay
- **Asymmetrical roles** — Hunter vs Specter
- **Mixed reality blending** — real world + digital entities
- **Real-time event system** — instant trigger responses
- **Time-pressure mechanics** — hunt before the clock hits zero

</td>
<td width="50%">

### 🛠 Technical
- **Modular C++ architecture** — clean, extensible controllers
- **Actor lifecycle management** — Unreal Engine best practices
- **Meta XR passthrough** — true mixed reality rendering
- **Multiplayer-ready structure** — built for future networking

</td>
</tr>
</table>

---

## 🧩 Architecture

```
SpecterHunterMR/
│
├── 📁 Source/
│   ├── 📁 Actors/
│   │   ├── 👻 GhostActor.h          ← Specter entity & behavior
│   │   └── 👻 GhostActor.cpp
│   │
│   ├── 📁 Controllers/
│   │   ├── 📡 ScannerController.h   ← Detection & event triggers
│   │   └── 📡 ScannerController.cpp
│   │
│   ├── 📁 GameModes/
│   │   └── 🎮 SpecterGameMode       ← Role assignment & game loop
│   │
│   └── 📁 UI/
│       └── 🖥  ScannerHUD           ← Hunter heads-up display
│
├── 📁 Config/
│   └── ⚙️  DefaultEngine.ini        ← XR & render settings
│
└── 📁 Build/
    └── 🔧 SpecterHunterMR.Build.cs  ← Module config (C#)
```

---

## 🔹 Core Components

<details>
<summary><b>👻 GhostActor — Click to expand</b></summary>

<br/>

The `GhostActor` is the heart of the Specter role. It manages:

```cpp
// Core responsibilities:
// ✦ Invisible movement through physical space
// ✦ Proximity detection for scare events
// ✦ State machine: Idle → Roaming → Fleeing → Caught

class AGhostActor : public AActor
{
    // Custom movement — bypasses physics for phase-through feel
    // Visibility toggle — hidden in base render, visible via scanner
    // Event dispatchers — notifies game mode on capture/escape
}
```

**Key behaviors:**
| State | Trigger | Behavior |
|---|---|---|
| 🌫 Roaming | Game start | Moves freely through the space |
| ⚠️ Detected | Scanner pulse hits | Briefly visible, speed increases |
| 🏃 Fleeing | Hunter proximity | Evades toward safe zones |
| 💀 Caught | Trap activation | Broadcasts capture event |

</details>

<details>
<summary><b>📡 ScannerController — Click to expand</b></summary>

<br/>

The `ScannerController` gives Hunters their primary tool:

```cpp
// Core responsibilities:
// ✦ Emit detection pulses from controller position
// ✦ Line/sphere trace against GhostActor collision
// ✦ Trigger haptic + audio feedback on detection
// ✦ Feed signal data to HUD for proximity display

class UScannerController : public UActorComponent
{
    // ScanPulse()      — emits sphere trace burst
    // OnHitDetected()  — fires when ghost overlaps
    // GetSignalStrength() — returns distance-based value
}
```

**Detection pipeline:**
```
[Trigger Press] → ScanPulse() → SphereTrace → Ghost Overlap?
                                                    │
                              No ──────────────────→ Idle
                                                    │
                              Yes ─────────────────→ HUD Alert
                                                     Haptic Feedback
                                                     Audio Cue
                                                     Ghost Stagger
```

</details>

---

## 🥽 XR Integration

```
Meta Quest Headset
        │
        ├── Passthrough Camera  ──→  Real world video feed
        │                             blended with UE5 scene
        │
        ├── 6DoF Tracking       ──→  Player position & rotation
        │                             mapped to in-game Hunter
        │
        ├── Controller Input    ──→  ScannerController trigger
        │                             mapped to left/right grip
        │
        └── Spatial Audio       ──→  Ghost proximity cues
                                      directional sound design
```

---

## 🚀 Getting Started

### Prerequisites

```bash
✅ Unreal Engine 5.1+       (Epic Games Launcher)
✅ Meta XR Plugin            (from Unreal Marketplace)
✅ Visual Studio 2022        (with C++ Game Dev workload)
✅ Meta Quest 2/3/Pro        (for device testing)
✅ Oculus PC App             (for Link / Air Link)
```

### Installation

```bash
# 1. Clone the repository
git clone https://github.com/zahid397/SpecterHunterMR.git
cd SpecterHunterMR

# 2. Right-click the .uproject file
#    → "Generate Visual Studio project files"

# 3. Open SpecterHunterMR.sln in Visual Studio 2022
#    → Build target: Development Editor | Win64

# 4. Launch the .uproject
#    → Unreal Editor will open

# 5. Enable Meta XR Plugin
#    Edit → Plugins → Search "Meta XR" → Enable → Restart
```

### Running on Device

```bash
# In Unreal Editor:
# 1. File → Project Settings → Platforms → Android
#    Set: Target SDK = 29+, Package = com.zahid.specterhuntermr

# 2. Edit → Project Settings → Meta XR
#    Enable: Passthrough, Hand Tracking, Spatial Audio

# 3. Platforms → Android → Package Project
#    Connect Quest via USB → Install APK
```

---

## 🧪 Development Challenges

<table>
<tr>
<td align="center" width="25%">
<br/>
<b>⚡ Real-time Logic</b>
<br/><br/>
Implementing frame-accurate<br/>interaction in C++ without<br/>blueprint overhead
</td>
<td align="center" width="25%">
<br/>
<b>🔄 Actor Lifecycle</b>
<br/><br/>
Managing spawn, possess,<br/>and destroy sequences<br/>across game states
</td>
<td align="center" width="25%">
<br/>
<b>🥽 XR Integration</b>
<br/><br/>
Bridging passthrough render<br/>pipeline with gameplay<br/>visibility states
</td>
<td align="center" width="25%">
<br/>
<b>🌐 Multiplayer Design</b>
<br/><br/>
Architecting systems<br/>for future network<br/>replication readiness
</td>
</tr>
</table>

---

## 🗺 Roadmap

```
v0.1 — Prototype (Current)
 ✅ GhostActor movement system
 ✅ ScannerController detection
 ✅ Meta XR passthrough integration
 ✅ Basic asymmetrical roles

v0.2 — Gameplay Polish
 🔲 Full scanner HUD with signal meter
 🔲 Ghost ability system (phase, stun, decoy)
 🔲 Sound design & spatial audio
 🔲 Score & round system

v0.3 — Multiplayer
 🔲 Unreal GameFramework networking
 🔲 2v1 / 3v1 player configurations
 🔲 Lobby & matchmaking flow
 🔲 Replicated ghost state

v1.0 — Release
 🔲 Full Meta Quest Store submission
 🔲 Tutorial & onboarding flow
 🔲 Leaderboard & progression
```

---

## 🛠 Tech Stack

<div align="center">

| Layer | Technology | Purpose |
|:---:|:---:|:---:|
| 🎮 Engine | **Unreal Engine 5** | Game runtime, rendering, physics |
| 💻 Language | **C++ 20** | Core gameplay systems & logic |
| 🥽 XR | **Meta XR Plugin** | Passthrough, 6DoF, hand tracking |
| 🔧 Build | **C# / .Build.cs** | Module & dependency configuration |
| 🌐 Network | **Unreal Networking** | *(planned — replication layer)* |

</div>

---

## 👨‍💻 Author

<div align="center">
<br/>

**Zahid Hasan**

*Frontend Developer · Data & Automation Engineer · Game Developer*

[![Email](https://img.shields.io/badge/Email-zh05698%40gmail.com-EA4335?style=for-the-badge&logo=gmail&logoColor=white)](mailto:zh05698@gmail.com)
[![GitHub](https://img.shields.io/badge/GitHub-zahid397-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/zahid397)

<br/>

*"Building at the intersection of AI, immersive tech, and real-world systems."*

</div>

---

## 📄 License

```
MIT License — feel free to explore, fork, and build on top of this.
If you use this work, a ⭐ star is always appreciated!
```

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,11,20&height=100&section=footer" width="100%"/>

**⭐ Star this repo if you find it interesting!**

*Built with 🎮 Unreal Engine 5 · 👻 Ghost Logic · 🥽 Meta XR*

</div>
