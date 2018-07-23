/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_RANKING_CONTROL_CALCIMMEDIATE_HPP_
#define GS2_RANKING_CONTROL_CALCIMMEDIATE_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/Gs2RankingConst.hpp>

namespace gs2 { namespace ranking {

/**
 * @author Game Server Services, Inc.
 */
class CalcImmediateRequest : public Gs2UserRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "CalcImmediate";

private:
    class Data : public Gs2Object
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ランキングテーブルのIDを指定します。 */
        optional<StringHolder> rankingTableId;
        /** ゲームモードの名前を指定します。 */
        optional<StringHolder> gameMode;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            ownerId(data.ownerId),
            rankingTableId(data.rankingTableId),
            gameMode(data.gameMode)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            ownerId(std::move(data.ownerId)),
            rankingTableId(std::move(data.rankingTableId)),
            gameMode(std::move(data.gameMode))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };
    
    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    CalcImmediateRequest() :
        m_pData(nullptr)
    {}

    CalcImmediateRequest(const CalcImmediateRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Ranking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CalcImmediateRequest(CalcImmediateRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Ranking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CalcImmediateRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CalcImmediateRequest& operator=(const CalcImmediateRequest& getMyRankRequest)
    {
        Gs2UserRequest::operator=(getMyRankRequest);
        Gs2Ranking::operator=(getMyRankRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMyRankRequest.m_pData);

        return *this;
    }

    CalcImmediateRequest& operator=(CalcImmediateRequest&& getMyRankRequest)
    {
        Gs2UserRequest::operator=(std::move(getMyRankRequest));
        Gs2Ranking::operator=(std::move(getMyRankRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMyRankRequest.m_pData;
        getMyRankRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    CalcImmediateRequest& withOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
        return *this;
    }

    /**
     * ランキングテーブルのIDを指定します。を取得
     *
     * @return ランキングテーブルのIDを指定します。
     */
    const optional<StringHolder>& getRankingTableId() const
    {
        return ensureData().rankingTableId;
    }

    /**
     * ランキングテーブルのIDを指定します。を設定
     *
     * @param rankingTableId ランキングテーブルのIDを指定します。
     */
    void setRankingTableId(const Char* rankingTableId)
    {
        ensureData().rankingTableId.emplace(rankingTableId);
    }

    /**
     * ランキングテーブルのIDを指定します。を設定
     *
     * @param rankingTableId ランキングテーブルのIDを指定します。
     */
    CalcImmediateRequest& withRankingTableId(const Char* rankingTableId)
    {
        ensureData().rankingTableId.emplace(rankingTableId);
        return *this;
    }

    /**
     * ゲームモードの名前を指定します。を取得
     *
     * @return ゲームモードの名前を指定します。
     */
    const optional<StringHolder>& getGameMode() const
    {
        return ensureData().gameMode;
    }

    /**
     * ゲームモードの名前を指定します。を設定
     *
     * @param gameMode ゲームモードの名前を指定します。
     */
    void setGameMode(const Char* gameMode)
    {
        ensureData().gameMode.emplace(gameMode);
    }

    /**
     * ゲームモードの名前を指定します。を設定
     *
     * @param gameMode ゲームモードの名前を指定します。
     */
    CalcImmediateRequest& withGameMode(const Char* gameMode)
    {
        ensureData().gameMode.emplace(gameMode);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CalcImmediateRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CalcImmediateRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CalcImmediateRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CalcImmediateRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    CalcImmediateRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_RANKING_CONTROL_CALCIMMEDIATE_HPP_