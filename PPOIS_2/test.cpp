#include "Header.h"
#include "gtest/gtest.h"

TEST(ClassTests, FoodTest) {
	Food Base, WithParam("AB", "TR", 15);
	EXPECT_EQ(Base.get_price(), 0);
	EXPECT_EQ(WithParam.get_price(), 15);

	EXPECT_EQ(Base.get_name(), "NONE");
	EXPECT_EQ(WithParam.get_name(), "AB");

	EXPECT_EQ(Base.get_taste(), "NONE");
	EXPECT_EQ(WithParam.get_taste(), "TR");

	EXPECT_EQ(Base.get_position(), -1);
	EXPECT_EQ(WithParam.get_position(), -1);
}

TEST(ClassTests, SongTest) {
	Song Base, WithParam("AB", "TR", "YO", 15);
	EXPECT_EQ(Base.get_style(), "NONE");
	EXPECT_EQ(WithParam.get_style(), "AB");

	EXPECT_EQ(Base.get_name(), "NONE");
	EXPECT_EQ(WithParam.get_name(), "TR");

	EXPECT_EQ(Base.get_author(), "NONE");
	EXPECT_EQ(WithParam.get_author(), "YO");

	EXPECT_EQ(Base.get_rating(), 0);
	EXPECT_EQ(WithParam.get_rating(), 15);
}

TEST(ClassTests, HumanTest) {
	Human Base, WithParam("AB", "TR", 14, 15);
	EXPECT_EQ(Base.get_name(), "G");
	EXPECT_EQ(WithParam.get_name(), "AB");

	EXPECT_EQ(Base.get_surname(), "G");
	EXPECT_EQ(WithParam.get_surname(), "TR");

	EXPECT_EQ(Base.get_money(), 0);
	EXPECT_EQ(WithParam.get_money(), 14);

	EXPECT_EQ(Base.get_age(), 0);
	EXPECT_EQ(WithParam.get_age(), 15);
}

TEST(ClassTests, WorkerTest) {
	Worker Base, WithParam("AB", "TR", 14, 15,13);
	EXPECT_EQ(Base.get_name(), "G");
	EXPECT_EQ(WithParam.get_name(), "AB");

	EXPECT_EQ(Base.get_surname(), "G");
	EXPECT_EQ(WithParam.get_surname(), "TR");

	EXPECT_EQ(Base.get_money(), 0);
	EXPECT_EQ(WithParam.get_money(), 14);

	EXPECT_EQ(Base.get_age(), 0);
	EXPECT_EQ(WithParam.get_age(), 15);

	EXPECT_EQ(Base.get_salary(), 0);
	EXPECT_EQ(WithParam.get_salary(), 13);

	WithParam.earn_money();
	EXPECT_EQ(WithParam.get_money(), 27);
	WithParam.get_tips(3);
	EXPECT_EQ(WithParam.get_money(), 30);
}

TEST(ClassTests, CookTest) {
	Cook Base, WithParam("AB", "TR", 14, 15, 13);
	EXPECT_EQ(Base.get_name(), "G");
	EXPECT_EQ(WithParam.get_name(), "AB");

	EXPECT_EQ(Base.get_surname(), "G");
	EXPECT_EQ(WithParam.get_surname(), "TR");

	EXPECT_EQ(Base.get_money(), 0);
	EXPECT_EQ(WithParam.get_money(), 14);

	EXPECT_EQ(Base.get_age(), 0);
	EXPECT_EQ(WithParam.get_age(), 15);

	EXPECT_EQ(Base.get_salary(), 0);
	EXPECT_EQ(WithParam.get_salary(), 13);
}

TEST(ClassTests, MusicianTest) {
	Musician Base, WithParam("AB", "TR", 14, 15, 13, "Rock");
	EXPECT_EQ(Base.get_name(), "G");
	EXPECT_EQ(WithParam.get_name(), "AB");

	EXPECT_EQ(Base.get_surname(), "G");
	EXPECT_EQ(WithParam.get_surname(), "TR");

	EXPECT_EQ(Base.get_money(), 0);
	EXPECT_EQ(WithParam.get_money(), 14);

	EXPECT_EQ(Base.get_age(), 0);
	EXPECT_EQ(WithParam.get_age(), 15);

	EXPECT_EQ(Base.get_salary(), 0);
	EXPECT_EQ(WithParam.get_salary(), 13);

	EXPECT_EQ(WithParam.get_style(), "Rock");
}

TEST(ClassTests, GuestTest) {
	Guest WithParam("AB", "TR", 14, 15);
	Worker Base;
	WithParam.give_tips(15, Base);

	EXPECT_EQ(Base.get_money(), 15);
}

TEST(ClassTests, KafeTest) {
	Kafe Base,WithParam("AB", "TR", 14, 15, 16, 17);

	EXPECT_EQ(Base.get_adres(), "NONE");
	EXPECT_EQ(WithParam.get_adres(), "TR");

	EXPECT_EQ(Base.get_name(), "NONE");
	EXPECT_EQ(WithParam.get_name(), "AB");

	EXPECT_EQ(Base.get_budjet(), 0);
	EXPECT_EQ(WithParam.get_budjet(), 16);

	EXPECT_EQ(Base.get_revenue(), 0);
	EXPECT_EQ(WithParam.get_revenue(), 15);

	EXPECT_EQ(Base.get_stars(), 0);
	EXPECT_EQ(WithParam.get_stars(), 14);

	EXPECT_EQ(Base.get_number_of_places(), 0);
	EXPECT_EQ(WithParam.get_number_of_places(), 17);
}

TEST(ClassTests, ManagmentTest) 
{
	BusinessManagment Base, WithParams(50);
	Kafe TestKafe("AB", "TR", 14, 15, 16, 17);
	Worker TestClerk;
	Base.buy_kafe(TestKafe); WithParams.buy_kafe(TestKafe);
	Base.hire_clerk(TestClerk); WithParams.hire_clerk(TestClerk);
	Base.earn_money(); WithParams.earn_money();
	Base.print_report(); WithParams.print_report();
}

TEST(WorkTests, KafeWorkProcces)
{
	Food Melon("Mel", "A", 5), Stew("Ste", "B", 2), Water("Wat", "C", 3), Cucumber("Cuc", "C", 7);
	Kafe Test_Kafe;
	Test_Kafe.add_to_menu(Melon);
	Test_Kafe.add_to_menu(Stew);
	Test_Kafe.add_to_menu(Water);
	Test_Kafe.add_to_menu(Cucumber);
	Guest Alesha, Misha, Pasha;
	Alesha.order(Melon); Alesha.order(Water); Misha.order(Stew); Misha.order(Stew); Pasha.order(Melon); Pasha.order(Cucumber); Pasha.order(Stew);
	Test_Kafe.add_to_queue(Alesha); Test_Kafe.add_to_queue(Misha); Test_Kafe.add_to_queue(Pasha);
	Cook Platon;
	Waiter Kom, Pon;
	Test_Kafe.hire_cook(Platon);
	Test_Kafe.hire_waiter(Kom); Test_Kafe.hire_waiter(Pon);
	Test_Kafe.work_procces();
	EXPECT_EQ(Test_Kafe.get_storage()[0],2);
	EXPECT_EQ(Test_Kafe.get_storage()[1], 3);
	EXPECT_EQ(Test_Kafe.get_storage()[2], 1);
	EXPECT_EQ(Test_Kafe.get_storage()[3], 1);
}
