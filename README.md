# GEANT4_2022 (고급물리실험)
### Last Update : 22/6/24<br>
### 🧭Where am I?
* Avalanche를 잘 묘사하는가? → (...)
* Next Tasks<br>
<del>중성자 검출기 He3 대체물질(${}^{10}\text{B} \,, {}^{6}\text{Li} \,, {}^{157}\text{Gd}$) 논의? α Gain? Sufficient for GEM?</del> → 시간부족<br>
<del>Chamber 불순물(습기, 압력, 질소 등)에 따른 노이즈 관찰?</del> → 시간부족<br>
<del>전기장 vs Gain (Operation Regime) 관찰?</del> → 전자 초기 KE에 따른 이온화 이벤트 회수 관측하는데에 그침 (부정확)<br>
<br>

### 📜List of Projects
* myGEM01 : GEM geometry 프로토타입<br>
  △ Chamber = [100μm × 100μm × 120μm] (2015, 최기진)<br>
* myGEM_acc : 전자가 전기장으로 제대로 가속되는가?<br>
  △ 그렇다 (제동복사로 인한 포톤 방출도 확인)<br>
* myGEM_ion : (전자/포톤에 의한) 이온화가 제대로 일어나는가?<br>
* **의문🤔** 전자는 일어나지만, 그 정도도 너무 약하고, 전기장이 약해서 Readout까지 도달하지 못합니다.<br>
  (2015, 최기진)의 실험조건 : 전기장(GEM 호일)=500V/60μm , GunEnergy=10~100k eV → Gain=0.3-13<br>
  myGEM_ion의 실험조건 : 전기장 동일, GunEnergy=0.5-15k eV → Gain=1.02-1.05<br>
  Gain은 출력/입력 전자 수이고, 제 경우는 UserSteppingAction을 통해서 이온화 횟수를 직접 세서 계산했습니다.<br>
  Secondary 중 Readout까지 가속하는 경우는 거의 없으며, 전자를 수 MeV로 쏘아야 (=전자를 수 keV에서 전기장을 GV/μm 오더로 걸어주어야)<br>
  한 두개 정도 도달하는 정도입니다. 그리고 무엇보다 위의 전기장을 거꾸로 걸어주어도 결과가 크게 달라지지 않습니다.<br>
  이런 결과는 EmStandard(Option3), Livermore, Penelope Model 모두에 공통적으로 나타납니다.<br>
* **의문🤔** 포톤은 이온화가 아예 일어나지 않습니다. EM모델(EmStandard, Penelope) 외에 어떤 모델이 필요할까요...?<br>

* ~~waterbody~~ (Abandoned) : 물으로 된 판자($\approx$성인남성)에 이것저것 쏴보자.<br>
△ 정량적으로 의미있는 결과를 얻기 힘들다고 판단했습니다. (Advanced/Extended 예제 이해는 제 역량이 안될 것 같고.. 결론이 인체의 영향이나 차폐성능이라면, 사실상 선량이나 조성비 문헌값을 검색하고 보고하는 발표가 될 것 같다고도 생각했습니다.) <br>
* ~~shield~~ (Abandoned) : 알파입자를 Puck-shaped $\text{Be}$ 샘플에 쏴보자. (입자와 샘플 바꿔서도 해보자)<br>
△ 중성자 생성이 매우 희박하다. (현실에서도 그러하지만, '비슷하게 희박한지'에 대한 비교가 어렵고, 그것을 통해 특별한 의미를 얻기 또한 어렵다고 판단했습니다. )<br>
△ 여러 입자/샘플을 비교하는 것은 정교한 모델 설정이 어렵기 때문에 정량적인 결과를 얻기 힘들다고 판단했습니다. (대신 최종발표 때 "이런 것이 가능하다" 차원에서 사진 한장을 쓸까 정도의 생각을 하고 있습니다.)<br>
△ γ나 전자만 한정해서, "Z에 따른 Energy Loss"를 보았어도 됐었을까... 지금와서 생각이 드네요.<br><br>

#### ※ NumberManager?
(SDManager, AnalysisManager 등) 여러 Manager Class를 만들기 게을러서 만든 유틸리티 클래스(싱글톤)입니다. **[필드값 참고]**<br>
- G4ThreeVector fBeamPort : ParticleGun 초기 위치 설정에 이용<br>
- G4double fSensorUnit : Sensitive Detector 크기에 사용하는 단위. Root에 Position Data 기록할 때 참조합니다.<br>
- G4int fSDHitCount, fRunCount : 각각 SD가 감지한 Hit의 수 & Run의 회차<br>
- G4double fEdep : Scoring Volume의 E Deposition (Accumulated thru events)<br>
- G4double fKin : SD가 감지한 Hit(PreStepPoint)의 KE (Accumulated thru events)<br>
- G4double fKin2 : fKin과 동일하나 KE²에 대한 값 (Fluctuation에 이용)<br>
