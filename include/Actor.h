#ifndef _ACTOR_H_
#define _ACTOR_H_

class Actor{
 private:
  virtual ~Actor()=0;

 protected:
  // vect mPosition;
  // vect mVelocity;
  // shape* mShape;

 public:
  Actor(/* vect position, vect velocity */);
  void update();

  // vect getPosition() const;
  // void setPosition(const vect  );

  // vect getVelocity() const;
  // void setVelocity(const vect  );
}

#endif
