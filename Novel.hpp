#ifndef NOVEL_HPP_
#define NOVEL_HPP_
#include <iostream>
#include <string>
#include <vector>

#include "Book.hpp"

struct review {
    double score_;
    std::string rating_;
};

class Novel: public Book {
    public:
        Novel();
        Novel(std::string title, std::string author, int page_count,
               std::string genre = "", bool is_digital_ = false,
              bool has_film_adaptation = false);
        std::string getGenre() const;
        void setGenre(std::string genre);
        std::vector<std::string> getCharacterList() const;
        std::string getCharacterListString() const;

        void addCharacter(std::string character) const;

        bool hasFilmAdaptation() const;

        void setFilmAdaptation() const;

        double getAverageRating() const;

        review createReview(double score, std::string rating);

        void addReview(review review_);
        void calculateAverageRating();

        private:
        std::string genre_;
        std::vector<std::string> character_list_;
        bool has_film_adaptation_;
        std::vector<review> reviews_;
        double average_rating_;
};

#endif