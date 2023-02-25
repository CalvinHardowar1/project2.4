#include "Novel.hpp"
#include "Book.hpp"

#include <iostream>
#include <string>
#include <vector>
Novel::Novel() {
  genre_ = " ";
  has_film_adaptation_ = false;
}
Novel::Novel(std::string title, std::string author, int page_count,
              std::string genre, bool is_digital_, bool has_film_adaptation)
    : Book(title, author, page_count, is_digital_),
      genre_(genre),
      has_film_adaptation_(has_film_adaptation) {}
std::string Novel::getGenre() const { return genre_; }

void Novel::setGenre(std::string genre) { genre_ = genre; }

std::vector<std::string> Novel::getCharacterList() const {
  return character_list_;
}

std::string Novel::getCharacterListString() const {
  std::string character_list_as_string = "";
  for (size_t i = 0; i < character_list_.size(); i++) {
    character_list_as_string += character_list_[i] + " ";
  }
  return character_list_as_string;
}

void Novel::addCharacter(std::string character) {
  character_list_.push_back(character);
}

double Novel::getAverageRating() const { return average_rating_; }

bool Novel::hasFilmAdaptation() const { return has_film_adaptation_; }

void Novel::setFilmAdaptation() { has_film_adaptation_ = true; }

review Novel::createReview(double score, std::string rating) {
  review new_review;
  new_review.score_ = score;
  new_review.rating_ = rating;
  return new_review;
}

void Novel::addReview(review review_) {
  reviews_.push_back(review_);
  calculateAverageRating();
}

void Novel::calculateAverageRating() {
  double sum = 0;
  for (size_t i = 0; i < reviews_.size(); i++) {
    sum += reviews_[i].score_;
  }
  average_rating_ = sum / reviews_.size();