#include "WorldCreateScene.hpp"
#include <ofGraphics.h>

WorldCreateScene::WorldCreateScene()
	: biomeLabel(),
	worldNameLabel(),
	sizeLabel(),
	worldNameInputField(),
	biomeDropdown(),
	sizeDropdown(),
	createButton(),
	backButton() {
}

void WorldCreateScene::mousePressed(int x, int y, int button) {
	worldNameInputField->mousePressed(x, y, button);
	biomeDropdown->mousePressed(x, y, button);
	sizeDropdown->mousePressed(x, y, button);
	createButton->mousePressed(x, y, button);
	backButton->mousePressed(x, y, button);
}

void WorldCreateScene::keyPressed(int key) {
	worldNameInputField->keyPressed(key);
}

void WorldCreateScene::keyReleased(int key) {
	worldNameInputField->keyReleased(key);
}

std::string WorldCreateScene::getWorldName() const {
	auto str = worldNameInputField->getText();
	if (str.empty()) {
		str = "MyWorld";
	}
	return str;
}

std::string WorldCreateScene::getBiome() const {
	return biomeDropdown->getSelectedItem();
}

std::string WorldCreateScene::getSize() const {
	return sizeDropdown->getSelectedItem();
}

void WorldCreateScene::onInit() {
	ofEnableAlphaBlending();
	glm::vec3 offset = glm::vec3(120, 240, 0);
	this->worldNameLabel = canvas.addComponent<ofxGameUI::Label>();
	this->biomeLabel = canvas.addComponent<ofxGameUI::Label>();
	this->sizeLabel = canvas.addComponent<ofxGameUI::Label>();
	this->worldNameInputField = canvas.addComponent<ofxGameUI::InputField>();
	this->biomeDropdown = canvas.addComponent<ofxGameUI::Dropdown>();
	this->sizeDropdown = canvas.addComponent<ofxGameUI::Dropdown>();
	this->createButton = canvas.addComponent<ofxGameUI::Button>();
	this->backButton = canvas.addComponent<ofxGameUI::Button>();
	//���[���h��: [  ]
	biomeLabel->text = u8"�o�C�I�[��";
	worldNameLabel->text = u8"���[���h��";
	worldNameInputField->fontSize = 40;
	sizeLabel->text = u8"�傫��";
	biomeDropdown->fontSize = 40;
	biomeDropdown->items.push_back("Stairs/Tree");
	biomeDropdown->items.push_back("Stairs/House");
	biomeDropdown->items.push_back("Plain/House");
	biomeDropdown->items.push_back("Plain/Tree");
	biomeDropdown->items.push_back("Hill");
	sizeDropdown->fontSize = 40;
	sizeDropdown->items.push_back("Small");
	sizeDropdown->items.push_back("Default");
	sizeDropdown->items.push_back("Big");
	createButton->text = u8"����";
	backButton->text = u8"�߂�";
	canvas.load();

	worldNameLabel->center(1280, 720);
	worldNameLabel->position.x -= 320;
	worldNameLabel->position.y = 10;
	worldNameInputField->center(1280, 720);
	worldNameInputField->position.y = 10;
	//�o�C�I�[��: [  ]
	biomeLabel->center(1280,720);
	biomeLabel->position.x -= 320;
	biomeLabel->position.y = 80;
	biomeDropdown->center(1280, 720);
	biomeDropdown->position.y = 80;
	//�傫��: [  ]
	sizeLabel->center(1280, 720);
	sizeLabel->position.x -= 320;
	sizeLabel->position.y = 150;
	sizeDropdown->center(1280, 720);
	sizeDropdown->position.y = 150;
	//�����{�^��
	createButton->center(1280, 720);
	//�߂�{�^��
	backButton->center(1280, 720);
	//���C�A�E�g�C��
	glm::vec3 up(0, -40, 0);
	worldNameLabel->position += offset + up;
	worldNameInputField->position += offset + up;
	biomeLabel->position += offset + up;
	biomeDropdown->position += offset + up;
	sizeLabel->position += offset + up;
	sizeDropdown->position += offset + up;
	createButton->position.y += offset.y;
	backButton->position.y += offset.y + createButton->getSize().y + 5;
	createButton->callback = std::bind(&WorldCreateScene::on_generate, this);
	backButton->callback = std::bind(&WorldCreateScene::on_back, this);
}

void WorldCreateScene::onShow() {
}

void WorldCreateScene::onUpdate() {
}

void WorldCreateScene::onDraw() {
	canvas.draw();
}

void WorldCreateScene::on_generate() {
	transition("Play");
}

void WorldCreateScene::on_back() {
	transition("Title");
}
