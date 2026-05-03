#include "/home/codeleaded/System/Static/Library/ConsoleEngine.h"
#include "/home/codeleaded/System/Static/Library/Rect.h"


CSprite XWing;
CSprite TFighter;
CSprite TBomber;
CSprite Bullet;

Vec2 player_p;
Vec2 player_v;
CSprite* playership;
Vector enemys; // Vector<Vec2>

void Reset(){
	Vector_Clear(&enemys);

	player_p.x = 1.0f;
	player_p.y = 1.0f;
	player_v.x = 0.0f;
	player_v.y = 0.0f;
}

void Setup(Console* c){
	XWing = CSprite_By(16,8,(wchar_t*)
		L"|              |"
		L"█              █"
		L"█              █"
		L"█              █"
		L"█              █"
		L"█____█▓▓▓▓█____█"
		L"█____██████____█"
		L"                "
	);
	TFighter = CSprite_By(16,8,(wchar_t*)
		L"                "
		L"█_█__██████__█_█"
		L"█_█__██████__█_█"
		L"█ █  █▓▓▓▓█  █ █"
		L"█ █          █ █"
		L"█_█          █_█"
		L"|||          |||"
		L"                "
	);
	TBomber = CSprite_By(16,8,(wchar_t*)
		L"███          ███"
		L"███ ████████ ███"
		L"████████████████"
		L"███ ██▓▓▓▓██ ███"
		L"███          ███"
		L"███          ███"
		L"███          ███"
		L"|||          |||"
	);
	Bullet = CSprite_By(16,8,(wchar_t*)
		L"       ██       "
		L"      ████      "
		L"     ██████     "
		L"    ████████    "
		L"    ||||||||    "
		L"    █||██||█    "
		L"    ▓||▓▓||▓    "
		L"    ▓▓▓▓▓▓▓▓    "
	);

	player_p = (Vec2){ 0.0f,0.0f };
	player_v = (Vec2){ 0.0f,0.0f };
	playership = &XWing;

	enemys = Vector_New(sizeof(Vec2));

	Reset();
}
void Update(Console* c){
	if(Console_Stroke(c,ALX_KEY_W).PRESSED)
		player_v.y = -10.0f;
	else if(Console_Stroke(c,ALX_KEY_S).PRESSED)
		player_v.y = 10.0f;
	else
		player_v.y = 0.0f;

	if(Console_Stroke(c,ALX_KEY_A).PRESSED)
		player_v.x = -10.0f;
	else if(Console_Stroke(c,ALX_KEY_D).PRESSED)
		player_v.x = 10.0f;
	else
		player_v.y = 0.0f;

	if(Console_Stroke(c,ALX_KEY_R).PRESSED)
		Reset();

	if(Console_Stroke(c,ALX_KEY_Q).PRESSED)
		c->Running = 0;
	

	player_p.x += player_v.x * c->ElapsedTime;
	player_p.y += player_v.y * c->ElapsedTime;
	

	//for(int i = 0;i<enemys.size;i++){
	//	Vec2 p = *(Vec2*)Vector_Get(&enemys,i);
	//	
	//	if(Rect_Overlap(Rect_New(player_p,(Vec2){ playership->w,playership->h }),Rect_New(p,(Vec2){ TFighter.w,TFighter.h }))){
	//		Reset();
	//	}
	//}

    Console_Clear(c,CPIXEL_SOLID,BG_BLACK);

	for(int i = 0;i<enemys.size;i++){
		Vec2 p = *(Vec2*)Vector_Get(&enemys,i);
		Console_RenderCSpriteFast(c,&TFighter,p.x - player_p.x,p.y);
	}
	
	Console_RenderCSpriteFast(c,playership,player_p.x,player_p.y);
}
void Delete(Console* c){
	CSprite_Free(&XWing);
	CSprite_Free(&TFighter);
	CSprite_Free(&TBomber);
	CSprite_Free(&Bullet);

    Vector_Free(&enemys);
}

int main(){
    Console c;
    
	if(Console_Create(&c,L"Game player",130,40,8,8,Setup,Update,Delete)){
		Console_Start(&c);
	}
	
    return 0;
}