# Moovers Racer - Development Roadmap

## Vertical Slice Sprint Plan (Weeks 0–8)

### Sprint 0–1: Foundation and Prototyping (Weeks 0–2)
**Goal**: Validate engine choice, physics feel, and rendering pipeline

- [ ] UE5 project generation and compilation
- [ ] ScooterPawn and ScooterPhysicsComponent polish
- [ ] Basic race track greybox (1 circuit, 3 laps)
- [ ] HUD mockup (speed, RPM, turbo gauge)
- [ ] Input mapping for touch and controller
- [ ] Performance baseline (target: 60 FPS on flagship)

**Deliverable**: Playable scooter with basic physics, one track, no customization

---

### Sprint 2–3: Customization System (Weeks 3–4)
**Goal**: Implement garage and parts system

- [ ] Part database creation (6+ parts minimum)
- [ ] GarageManager implementation
- [ ] 3D garage scene with preview
- [ ] Part equipping/unequipping UI
- [ ] Stat recalculation and visual feedback
- [ ] Part visuals (modular meshes, materials)

**Deliverable**: Functional garage with customizable parts affecting gameplay

---

### Sprint 4: Polish and Optimization (Weeks 5–8)
**Goal**: Visual, audio, and performance pass

- [ ] Scooter model final visuals (3 variants)
- [ ] Track lighting and environment details
- [ ] Audio implementation:
  - [ ] Engine sound with RPM modulation
  - [ ] Foley (clutch, exhaust, turbo)
  - [ ] Race music (adaptive intensity)
- [ ] HUD polish and animation
- [ ] Performance optimization:
  - [ ] LOD setup
  - [ ] Texture streaming
  - [ ] Scalability presets
- [ ] QA pass (device compatibility, stability)

**Deliverable**: Polished vertical slice ready for presentation

---

## Full Game Roadmap (Weeks 9–32)

### Sprint 5–8: Core Features (Weeks 9–16)
- Career mode storyline (5 story beats)
- Time trials with ghost system
- Extended parts catalog (30+ parts)
- 3 unique track environments
- Leaderboard integration (backend)

### Sprint 9–12: Content and Polish (Weeks 17–24)
- Photo mode implementation
- Seasonal cosmetic system
- Extended scooter lineup (10+ models)
- Advanced physics tuning
- UI/UX refinement

### Sprint 13–16: Launch Prep (Weeks 25–32)
- Beta testing on device fleet
- Performance profiling and optimization
- Monetization integration (IAP, ads)
- Localization (Spanish, Italian, Japanese)
- App store submission prep

---

## Key Milestones

| Milestone | Target Date | Status |
|-----------|-------------|--------|
| Vertical Slice (Internal) | Week 8 | Not Started |
| Feature Complete | Week 20 | Not Started |
| Closed Beta | Week 24 | Not Started |
| Launch Ready | Week 32 | Not Started |
| Public Launch | Week 36+ | TBD |

---

## Ownership and Dependencies

| System | Owner | Status |
|--------|-------|--------|
| Physics & Handling | Lead Designer | In Progress |
| Art & Visuals | Lead Artist | Pending Greenlight |
| Audio | Audio Lead | Pending Audio Assets |
| Garage UI | UI Engineer | Pending Design Sign-off |
| Leaderboards | Network Engineer | Pending Backend Design |
| QA & Performance | QA Lead | Pending Vertical Slice |

---

## Risks and Mitigation

| Risk | Severity | Mitigation |
|------|----------|-----------|
| Mobile performance overhead | High | Early optimization pass, scalable presets, aggressive LODs |
| Physics feel too arcade-y | Medium | Designer tuning pass, player feedback early and often |
| Part economy imbalance | Medium | Playtesting, telemetry on part usage, iterative balance |
| Leaderboard sync failures | Medium | Backend load testing, retry logic, offline fallback |

---

**Next Meeting**: End of Sprint 1 (Week 2) for playability checkpoint
