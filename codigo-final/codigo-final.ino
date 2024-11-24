#include <Servo.h>



// definição de constantes para angulos iniciais e pinos

const int BRACO_PIN = 9;
const int PROFUNDOR_PIN = 8;
const int GARA_PIN = 7;
const int BASE_PIN = 6;

const int BRACO_INICIAL = 120;
const int PROFUNDOR_INICIAL = 75;
const int GARA_INICIAL = 40;
const int BASE_INICIAL = 98;


const int GARA_FECHADA = 10;
const int BRACO_ERGUIDO = 120;
const int BRACO_ABAIXADO = 165;
// definicao de variaveis

int cont = 0;
int cont2 = 0;

// defini posicoes do primeiro objeto. PEGAR

const int PROFUNDOR_OBJ_1 = 91;
const int BASE_OBJ_1_PEGA = 58;

// define posicoes do primeiro objeto. SOLTAR
const int BASE_OBJ_1_SOLTA = 160;

//posicao para pegar segundo objeto
const int BASE_OBJ_2_PEGA = 29;
const int BRACO_OBJ_2_ABAIXADO = 165;
const int PROFUNDOR_OBJ_2_PEGAR = 79;
const int BASE_OBJ_2_SOLTAR = 124;

// posicao para segundo obj
const int BASE_OBJ_3_PEGAR = 12;
const int BASE_OBJ_3_SOLTAR = 98;

// quarto local
const int BASE_LOCAL_4 = 64;

Servo bracoServo;
Servo profundorServo;
Servo garaServo;
Servo baseServo;

void setup() {
  bracoServo.attach(BRACO_PIN);
  profundorServo.attach(PROFUNDOR_PIN);
  garaServo.attach(GARA_PIN);
  baseServo.attach(BASE_PIN);

  // inicializa os servos na posicao inicial
  moveToPosition(BRACO_INICIAL, PROFUNDOR_INICIAL, GARA_INICIAL, BASE_INICIAL);
  delay(1000);

}

void loop() {
  delay(100);
  moveToPosition(BRACO_ERGUIDO, PROFUNDOR_INICIAL, GARA_INICIAL, BASE_INICIAL);

// chama as funcoes com os movimentos
  if (cont < 0) {
    manda_pegar_primeiro();
    manda_pegar_segundo();
    manda_pegar_terceiro();
    cont += 1;
  }
  pega_posicao_1();
  delay(100);
  leva_posicao3_para1();
  delay(100);
  leva_posicao2_para3();
  delay(100);
  leva_posicao4_para2();
  delay(100);
}

void moveToPosition(int bracoAngle, int profundorAngle, int garaAngle, int baseAngle) {

  bracoServo.write(bracoAngle);
  profundorServo.write(profundorAngle);
  garaServo.write(garaAngle);
  baseServo.write(baseAngle);
}

// primeiro objeto
void manda_pegar_primeiro() {

  base_pega_primeiro();
  estica_profundor();
  abaixar_braco();
  fecha_gara();
  erguer_braco();
  base_solta_obj();
  abaixar_braco();
  abre_gara();
  erguer_braco();
  profundor_volta_inicial();
}

// movimento para segundo objeto
void manda_pegar_segundo() {
  base_pegar_segundo_obj();
  profundor_pegar_segundo();
  braco_abaixado_2();
  fecha_gara();
  braco_erguido_2();
  base_soltar_segundo();
  profundor_alinha_objetos();
  abaixar_braco();
  abre_gara();
  braco_erguido_2();
  profundor_volta_inicial();
}

// movimento para terceiro objeto
void manda_pegar_terceiro() {
  base_obj_3_pega();
  profundor_pegar_segundo();
  braco_abaixado_2();
  fecha_gara();
  braco_erguido_2();
  profundor_alinha_objetos();
  base_obj_3_solta();
  braco_abaixado_2();
  abre_gara();
  erguer_braco();
  profundor_volta_inicial();
}
  
void pega_posicao_1() {
  if (cont2 < 1) {
    resgata_posicao_1();
    cont2 += 0;
  }
  else{
    base_volta_para_pos1();
  }
  
  estica_profundor();
  abaixar_braco();
  fecha_gara();
  erguer_braco();
  solta_na_posicao_4();
  abaixar_braco();
  abre_gara();
  erguer_braco();
}

void leva_posicao3_para1()  {
  base_pega_3_para1();
  abaixar_braco();
  fecha_gara();
  erguer_braco();
  base_solta_3_para1();
  abaixar_braco();
  abre_gara();
  erguer_braco();
}

void leva_posicao2_para3()  {
  base_pega_2_para3();
  abaixar_braco();
  fecha_gara();
  erguer_braco();
  base_solta_2_para3();
  abaixar_braco();
  abre_gara();
  erguer_braco();
}
void leva_posicao4_para2()  {
  base_pega_4_para2();
  abaixar_braco();
  fecha_gara();
  erguer_braco();
  base_solta_4_para2();
  abaixar_braco();
  abre_gara();
  erguer_braco();

}
  // funcao para pegar o primeiro obj
void base_pega_primeiro()  {
  for (int pos_base = BASE_INICIAL; pos_base >= BASE_OBJ_1_PEGA; pos_base -= 1) {
    baseServo.write(pos_base);
    delay(10);
  }
}

// leva a garra para a pocisao de pegar objetos
void estica_profundor()  {
  for (int pos_profundor = PROFUNDOR_INICIAL; pos_profundor <= PROFUNDOR_OBJ_1; pos_profundor +=1) {
    profundorServo.write(pos_profundor);
    delay(10);
  }
}

void fecha_gara()  {
  for (int pos_gara = GARA_INICIAL; pos_gara >= GARA_FECHADA; pos_gara -= 1)  {
  garaServo.write(pos_gara);
  delay(10);
  }
}
void erguer_braco() {
  for (int pos_altura = BRACO_ABAIXADO; pos_altura >= BRACO_ERGUIDO; pos_altura -= 1)  {
    bracoServo.write(pos_altura);
    delay(10);
  }
}

void base_solta_obj() {
  for (int pos_base = BASE_OBJ_1_PEGA; pos_base <= BASE_OBJ_1_SOLTA; pos_base += 1) {
    baseServo.write(pos_base);
    delay(10);
  }
}

void abaixar_braco() {
  for (int pos_altura = BRACO_ERGUIDO; pos_altura <= BRACO_ABAIXADO; pos_altura += 1)  {
    bracoServo.write(pos_altura);
    delay(20);
  }
}

void abre_gara()  {
  for (int pos_gara = GARA_FECHADA; pos_gara <= GARA_INICIAL; pos_gara += 1)  {
    garaServo.write(pos_gara);
    delay(10);
  }
}

//SEGUNDO OBJ

void base_pegar_segundo_obj() {
  for (int pos_base = BASE_OBJ_1_SOLTA; pos_base >= BASE_OBJ_2_PEGA; pos_base -= 1) {
    baseServo.write(pos_base);
    delay(10);
  }
}

//volta o profundor a posicao inicial de forma controlada
void profundor_volta_inicial()  {
  for (int pos_profundor = PROFUNDOR_OBJ_1; pos_profundor >= PROFUNDOR_INICIAL; pos_profundor -= 1) {
    profundorServo.write(pos_profundor);
    delay(10);
  }
}

void profundor_pegar_segundo()  {
  for (int pos_profundor = PROFUNDOR_INICIAL; pos_profundor <= PROFUNDOR_OBJ_2_PEGAR; pos_profundor += 1) {
    profundorServo.write(pos_profundor);
    delay(10);
  }
}

void braco_abaixado_2() { 
  for (int pos_braco = BRACO_ERGUIDO; pos_braco <= BRACO_OBJ_2_ABAIXADO; pos_braco += 1) {
    bracoServo.write(pos_braco);
    delay(20);
  }
}

void braco_erguido_2()  {
  for (int pos_braco = BRACO_OBJ_2_ABAIXADO; pos_braco >= BRACO_ERGUIDO; pos_braco -= 1) {
    bracoServo.write(pos_braco);
    delay(10);
  }
}

void base_soltar_segundo()  {
  for (int pos_base = BASE_OBJ_2_PEGA; pos_base <= BASE_OBJ_2_SOLTAR; pos_base += 1) {
    baseServo.write(pos_base);
    delay(10);
  }
}

void profundor_alinha_objetos()  {
  for (int pos_profundor = PROFUNDOR_OBJ_2_PEGAR; pos_profundor >= PROFUNDOR_OBJ_1; pos_profundor -= 1) {
    profundorServo.write(pos_profundor);
    delay(10);
  }
}

void base_obj_3_pega()  {
  for (int pos_base = BASE_OBJ_2_SOLTAR; pos_base >= BASE_OBJ_3_PEGAR; pos_base -= 1) {
    baseServo.write(pos_base);
    delay(10);
  }
}

void base_obj_3_solta() {
  for (int pos_base = BASE_OBJ_3_PEGAR; pos_base <= BASE_OBJ_3_SOLTAR; pos_base += 1) {
    baseServo.write(pos_base);
    delay(10);
  }
}

// funcoes para embaralhar objetos

void resgata_posicao_1()  {
  for (int local_base = BASE_OBJ_3_SOLTAR; local_base <= BASE_OBJ_1_SOLTA; local_base += 1) {
    baseServo.write(local_base);
    delay(10);
  }
}

void solta_na_posicao_4() {
  for (int local_base = BASE_OBJ_1_SOLTA; local_base >= BASE_LOCAL_4; local_base -= 1)  {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_pega_3_para1()  {
  for (int local_base = BASE_LOCAL_4; local_base <= BASE_OBJ_3_SOLTAR; local_base += 1) {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_solta_3_para1() {
  for (int local_base = BASE_OBJ_3_SOLTAR; local_base <= BASE_OBJ_1_SOLTA; local_base += 1) {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_pega_2_para3()  {
  for (int local_base = BASE_OBJ_1_SOLTA; local_base >= BASE_OBJ_2_SOLTAR; local_base -= 1) {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_solta_2_para3() {
  for (int local_base = BASE_OBJ_2_SOLTAR; local_base >= BASE_OBJ_3_SOLTAR; local_base -= 1) {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_pega_4_para2()  {
  for (int local_base = BASE_OBJ_3_SOLTAR; local_base >= BASE_LOCAL_4; local_base -=1)  {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_solta_4_para2() {
  for (int local_base = BASE_LOCAL_4; local_base <= BASE_OBJ_2_SOLTAR; local_base += 1) {
    baseServo.write(local_base);
    delay(10);
  }
}

void base_volta_para_pos1() {
  for (int local_base = BASE_OBJ_2_SOLTAR; local_base > BASE_OBJ_1_SOLTA; local_base -= 1)  {
    baseServo.write(local_base);
    delay(10);
  }
}