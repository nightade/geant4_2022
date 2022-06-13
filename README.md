# GEANT4_2022 (고급물리실험)
### 🚨Tasks soon to be done
* Avalanche를 잘 묘사하는가?
* 마무리방향: He3
<br><br>

### 📜List of Projects
* **myGEM_acc** : 전자가 전기장으로 제대로 가속되는가?<br>
△ 그렇다.
<br><br>
* **myGEM_ion** : (전자/γ에 의한) 이온화가 제대로 일어나는가?<br>
△ 
<br><br>
* ~~myGEM01~~ (Abandoned) : prototype of GEM geometry<br>
* ~~waterbody~~ (Abandoned) : 물으로 된 판자($\approx$성인남성)에 이것저것 쏴보자.<br>
△ 차폐'일상생활'의 <br>
* ~~shield~~ (Abandoned) : 알파입자를 Puck-shaped $\text{Be}$ 샘플에 쏴보자. (입자와 샘플 바꿔서도 해보자)<br>
△ 중성자 생성이 매우 희박하다. (현실에서도 그러하지만, '비슷하게 희박한지'에 대한 비교가 어렵고, 그것을 통해 특별한 의미를 얻기 또한 어렵다고 판단했습니다. )<br>
△ 여러 입자/샘플을 비교하는 것은 정교한 모델 설정이 어렵기 때문에 정량적인 결과를 얻기 힘들다고 판단했습니다. (대신 최종발표 때 "이런 것이 가능하다" 차원에서 사진 한장을 쓸까 정도의 생각을 하고 있습니다.)<br>
△ γ나 전자만 한정해서 Z에 따른 Energy Loss는 해볼만 했던 것 같습니다.~~흠~~<br><br>

### 🤔QUESTION BOX
* **[myGEM_acc]** 왜 W / eEd = 0.91 일까?<br>
...$W = KE_{SD} - KE_{0}$<br>
...KE_SD = PreStepPoint->GetKineticEnergy()<br>
...KE_0 = Gun Particle Energy<br>
* **[myGEM_ion]** 왜 이온화가 안될까?<br>
* [minor issue] G4_Galactic은 진공으로 취급해도 괜찮은가?
<br><br>

#### ※ NumberManager?
(SDManager, AnalysisManager 등) 여러 Manager Class를 만들기 게을러서 만든 유틸리티 클래스(싱글톤)입니다. **[필드값 참고]**<br>
- G4ThreeVector fBeamPort : ParticleGun 초기 위치 설정에 이용<br>
- G4double fSensorUnit : Sensitive Detector 크기에 사용하는 단위. Root에 Position Data 기록할 때 참조합니다.<br>
- G4int fSDHitCount, fRunCount : 각각 SD가 감지한 Hit의 수 & Run의 회차<br>
- G4double fEdep : Scoring Volume의 E Deposition (Accumulated thru events)<br>
- G4double fKin : SD가 감지한 Hit(PreStepPoint)의 KE (Accumulated thru events)<br>
- G4double fKin2 : fKin과 동일하나 KE²에 대한 값 (Fluctuation에 이용)<br>
